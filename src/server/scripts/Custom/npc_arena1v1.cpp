/*
*TER-Server
*/

#include "ScriptMgr.h"
#include "ArenaTeamMgr.h"
#include "Common.h"
#include "DisableMgr.h"
#include "BattlegroundMgr.h"
#include "Battleground.h"
#include "ArenaTeam.h"
#include "Language.h"
#include "npc_arena1v1.h"


class npc_1v1arena : public CreatureScript
{
public:
	npc_1v1arena() : CreatureScript("npc_1v1arena")
	{
	}


	bool JoinQueueArena(Player* player, Creature* me, bool isRated)
	{
		if (!player || !me)
			return false;

		if (sWorld->getIntConfig(CONFIG_ARENA_1V1_MIN_LEVEL) > player->getLevel())
			return false;

		ObjectGuid guid = player->GetGUID();
		uint8 arenaslot = ArenaTeam::GetSlotByType(ARENA_TEAM_5v5);
		uint8 arenatype = ARENA_TYPE_5v5;
		uint32 arenaRating = 0;
		uint32 matchmakerRating = 0;

		// ignore if we already in BG or BG queue
		if (player->InBattleground())
			return false;

		//check existance
		Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BATTLEGROUND_AA);
		if (!bg)
		{
			sLog->outError(LOG_FILTER_SQL, "Battleground: template bg (all arenas) not found");
			return false;
		}

		if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, BATTLEGROUND_AA, NULL))
		{
			ChatHandler(player->GetSession()).PSendSysMessage(LANG_ARENA_DISABLED);
			return false;
		}

		BattlegroundTypeId bgTypeId = bg->GetTypeID();
		BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, arenatype);
		PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), player->getLevel());
		if (!bracketEntry)
			return false;

		GroupJoinBattlegroundResult err = ERR_BATTLEGROUND_JOIN_FAILED;

		// check if already in queue
		if (player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
			//player is already in this queue
			return false;
		// check if has free queue slots
		if (!player->HasFreeBattlegroundQueueId())
			return false;

		uint32 ateamId = 0;

		if (isRated)
		{
			ateamId = player->GetArenaTeamId(arenaslot);
			ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(ateamId);
			if (!at)
			{
				player->GetSession()->SendNotInArenaTeamPacket(arenatype);
				return false;
			}

			// get the team rating for queueing
			arenaRating = at->GetRating();
			matchmakerRating = arenaRating;
			// the arenateam id must match for everyone in the group

			if (arenaRating <= 0)
				arenaRating = 1;
		}

		BattlegroundQueue &bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
		bg->SetRated(isRated);

		GroupQueueInfo* ginfo = bgQueue.AddGroup(player, NULL, bgTypeId, bracketEntry, arenatype, isRated, false, arenaRating, matchmakerRating, ateamId);
		uint32 avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->GetBracketId());
		uint32 queueSlot = player->AddBattlegroundQueueId(bgQueueTypeId);

		WorldPacket data;
		// send status packet (in queue)
		sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, player, queueSlot, STATUS_WAIT_QUEUE, avgTime, 0, arenatype);
		player->GetSession()->SendPacket(&data);

		sBattlegroundMgr->ScheduleQueueUpdate(matchmakerRating, arenatype, bgQueueTypeId, bgTypeId, bracketEntry->GetBracketId());

		return true;
	}


	bool CreateArenateam(Player* player, Creature* me)
	{
		if (!player || !me)
			return false;

		uint8 slot = ArenaTeam::GetSlotByType(ARENA_TEAM_5v5);
		if (slot >= MAX_ARENA_SLOT)
			return false;

		// Check if player is already in an arena team
		if (player->GetArenaTeamId(slot))
		{
			player->GetSession()->SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, player->GetName(), "", ERR_ALREADY_IN_ARENA_TEAM);
			return false;
		}


		// Teamname = playername
		// if teamname exist, we have to choose another name (playername + number)
		int i = 1;
		std::stringstream teamName;
		teamName << player->GetName();
		do
		{
			if (sArenaTeamMgr->GetArenaTeamByName(teamName.str()) != NULL) // teamname exist, so choose another name
			{
				teamName.str(std::string());
				teamName << player->GetName() << (i++);
			}
			else
				break;
		} while (i < 100); // should never happen

		// Create arena team
		ArenaTeam* arenaTeam = new ArenaTeam();

		if (!arenaTeam->Create(player->GetGUID(), ARENA_TEAM_5v5, teamName.str(), 4283124816, 45, 4294242303, 5, 4294705149))
		{
			delete arenaTeam;
			return false;
		}

		// Register arena team
		sArenaTeamMgr->AddArenaTeam(arenaTeam);
		arenaTeam->AddMember(player->GetGUID());

		ChatHandler(player->GetSession()).SendSysMessage("Команда на арену успешно создана!");

		return true;
	}


	bool OnGossipHello(Player* player, Creature* me)
	{
		if (!player || !me)
			return true;

		if (sWorld->getBoolConfig(CONFIG_ARENA_1V1_ENABLE) == false)
		{
			ChatHandler(player->GetSession()).SendSysMessage("Арена не доступна!");
			return true;
		}

		if (player->InBattlegroundQueueForBattlegroundQueueType(BATTLEGROUND_QUEUE_5v5))
			player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_CHAT, "Встать в очередь на Арену", GOSSIP_SENDER_MAIN, 3, "Вы уверены?", 0, false);
		else
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Зарегестрироваться без Рейтинга", GOSSIP_SENDER_MAIN, 20);

		if (player->GetArenaTeamId(ArenaTeam::GetSlotByType(ARENA_TEAM_5v5)) == 0)
			player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_CHAT, "Создать команду", GOSSIP_SENDER_MAIN, 1, "Вы уверены?", sWorld->getIntConfig(CONFIG_ARENA_1V1_COSTS), false);
		else
		{
			if (player->InBattlegroundQueueForBattlegroundQueueType(BATTLEGROUND_QUEUE_5v5) == false)
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Зарегестрироваться с Рейтингом", GOSSIP_SENDER_MAIN, 2);
				player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_CHAT, "Распустить команду", GOSSIP_SENDER_MAIN, 5, "Вы уверены?", 0, false);
			}

			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Показать статистику", GOSSIP_SENDER_MAIN, 4);
		}

		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Информация", GOSSIP_SENDER_MAIN, 8);
		player->SEND_GOSSIP_MENU(68, me->GetGUID());
		return true;
	}



	bool OnGossipSelect(Player* player, Creature* me, uint32 /*uiSender*/, uint32 uiAction)
	{
		if (!player || !me)
			return true;

		player->PlayerTalkClass->ClearMenus();

		switch (uiAction)
		{
		case 1: // Create new Arenateam
		{
			if (sWorld->getIntConfig(CONFIG_ARENA_1V1_MIN_LEVEL) <= player->getLevel())
			{
				if (player->GetMoney() >= sWorld->getIntConfig(CONFIG_ARENA_1V1_COSTS) && CreateArenateam(player, me))
					player->ModifyMoney(sWorld->getIntConfig(CONFIG_ARENA_1V1_COSTS) * -1);
			}
			else
			{
				ChatHandler(player->GetSession()).PSendSysMessage("Вам нужен уровень %u+ чтобы создать команду.", sWorld->getIntConfig(CONFIG_ARENA_1V1_MIN_LEVEL));
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
		}
		break;

		case 2: // Join Queue Arena (rated)
		{
			if (Arena1v1CheckTalents(player) && JoinQueueArena(player, me, true) == false)
				ChatHandler(player->GetSession()).SendSysMessage("Не удалось встать в очередь");

			player->CLOSE_GOSSIP_MENU();
			return true;
		}
		break;

		case 20: // Join Queue Arena (unrated)
		{
			if (Arena1v1CheckTalents(player) && JoinQueueArena(player, me, false) == false)
				ChatHandler(player->GetSession()).SendSysMessage("Не удалось встать в очередь");

			player->CLOSE_GOSSIP_MENU();
			return true;
		}
		break;

		case 3: // Leave Queue
		{
			WorldPacket Data;
			Data << (uint8)0x1 << (uint8)0x0 << (uint32)BATTLEGROUND_AA << (uint16)0x0 << (uint8)0x0;
			player->GetSession()->HandleBattleFieldPortOpcode(Data);
			player->CLOSE_GOSSIP_MENU();
			return true;
		}
		break;

		case 4: // get statistics
		{
			ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(player->GetArenaTeamId(ArenaTeam::GetSlotByType(ARENA_TEAM_5v5)));
			if (at)
			{
				std::stringstream s;
				s << "рейтинг,: " << at->GetStats().Rating;
				s << "\nРанк: " << at->GetStats().Rank;
				s << "\nСезон игры: " << at->GetStats().SeasonGames;
				s << "\nПобед в сезоне: " << at->GetStats().SeasonWins;
				s << "\nИгр на неделе: " << at->GetStats().WeekGames;
				s << "\nПобед на этой неделе: " << at->GetStats().WeekWins;

				ChatHandler(player->GetSession()).PSendSysMessage(s.str().c_str());
			}
		}
		break;


		case 5: // Disband arenateam
		{
			WorldPacket Data;
			Data << (uint32)player->GetArenaTeamId(ArenaTeam::GetSlotByType(ARENA_TEAM_5v5));
			player->GetSession()->HandleArenaTeamLeaveOpcode(Data);
			ChatHandler(player->GetSession()).SendSysMessage("Команда удалена!");
			player->CLOSE_GOSSIP_MENU();
			return true;
		}
		break;

		case 8: // Script Info
		{
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "TER-Server крови", GOSSIP_SENDER_MAIN, uiAction);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Участие на Арене 1 на 1", GOSSIP_SENDER_MAIN, uiAction);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Просто зарегестрируйся на участие", GOSSIP_SENDER_MAIN, uiAction);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "<-- Вернуться назад", GOSSIP_SENDER_MAIN, 7);
			player->SEND_GOSSIP_MENU(68, me->GetGUID());
			return true;
		}
		break;

		}

		OnGossipHello(player, me);
		return true;
	}
};


void AddSC_npc_1v1arena()
{
	new npc_1v1arena();
}