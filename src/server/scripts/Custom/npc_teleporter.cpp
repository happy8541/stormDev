/*
 * Copyright (C) 2016 DeathCore <http://www.noffearrdeathproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// Chat Icons
//CHAT_ICON = 0
//VENDOR_ICON = 1
//FLIGHT_ICON = 2
//TRAINER_ICON = 3
//GEAR_ICON = 4
//GEAR_ICON_2 = 5
//BANK_ICON = 6
//CHAT_DOTS_ICON = 7
//TABARD_ICON = 8
//SWORDS_ICON = 9
//GOLD_DOT_ICON = 10

#define ERROR_COMBAT "|cffff0000You are in Combat!|r"

class GossipNpc : public CreatureScript
{
public:
	GossipNpc() : CreatureScript("GossipNpc") { }

	bool OnGossipHello(Player* plr, Creature* npc)
	{
		if (plr->IsInCombat())
		{
			ChatHandler(plr->GetSession()).PSendSysMessage(ERROR_COMBAT);
			return false;
		}

		plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Achievement_Reputation_01:30|t  Таверна Катаклизма", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
		plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Achievement_Dungeon_AzjolLowercity:30|t Города", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
		plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Achievement_BG_winWSG:30|t  Зона для дуэлей", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
		plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\INV_Misc_Wrench_01:30|t  Зона реагентов", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
		plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\INV_Mask_01:30|t  Шаттрат Для всех", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
		plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\ACHIEVEMENT_ARENA_2V2_1:30|t Арена Гурубаши", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
		plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\ACHIEVEMENT_GUILDPERK_HONORABLEMENTION:30|t Зона фарма хонораr", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 77);
		plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Ability_Hunter_MendPet:30|t Зона для Охотников", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
		plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Achievement_Zone_TolBarad:30|t Baradin Hold - Рейд Катаклизма", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
		plr->ADD_GOSSIP_ITEM(9, "|TInterface\\icons\\Achievement_BG_returnXflags_def_WSG:30|t Закрыть", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 99);
		plr->SEND_GOSSIP_MENU(1, npc->GetGUID());
		return true;
	}
	bool OnGossipSelect(Player* plr, Creature* npc, uint32 sender, uint32 uiAction)
	{
		if (!plr)
			return false;

		plr->PlayerTalkClass->ClearMenus();

		switch (uiAction)
		{

		case GOSSIP_ACTION_INFO_DEF + 1: //Mall Teleport
			plr->TeleportTo(0, -2723.567871f, -5356.419434f, 177.281921f, 2.535085f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 2:
			if (plr->GetTeam() == ALLIANCE){
				plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Spell_Arcane_TeleportStormWind:30|t Stormwind", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
				plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Spell_Arcane_TeleportIronForge:30|t Ironforge", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
				plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Spell_Arcane_TeleportDarnassus:30|t Darnassus", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
				plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Spell_Arcane_TeleportExodar:30|t Exodar", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
				plr->ADD_GOSSIP_ITEM(9, "|TInterface\\icons\\Achievement_General_CityAttacker:30|t Атака на Огримар", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
				plr->ADD_GOSSIP_ITEM(9, "|TInterface\\icons\\Achievement_BG_returnXflags_def_WSG:30|t Выход", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 99);
			}
			else if (plr->GetTeam() == HORDE){
				plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Spell_Arcane_TeleportOrgrimmar:30|t Orgrimmar", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15);
				plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Spell_Arcane_TeleportUnderCity:30|t Undercity", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Spell_Arcane_TeleportThunderBluff:30|t Thunder Bluff", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 17);
				plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Spell_Arcane_TeleportSilvermoon:30|t Silvermoon", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 18);
				plr->ADD_GOSSIP_ITEM(9, "|TInterface\\icons\\Achievement_General_CityAttacker:30|t Атака на Шторм!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 19);
				plr->ADD_GOSSIP_ITEM(9, "|TInterface\\icons\\Achievement_BG_returnXflags_def_WSG:30|t Выход", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 99);
			}
			plr->SEND_GOSSIP_MENU(1, npc->GetGUID());
			break;

		case GOSSIP_ACTION_INFO_DEF + 3: // Zona de Duelo
			plr->TeleportTo(0, -3575.618652f, -5004.466797f, 33.229931f, 5.351537f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 4: // Zona de ProfissГµes
			plr->TeleportTo(571, 5829.209473f, 476.326782f, 658.231628f, 4.316894f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 5: // Zona de Transmogrification
			plr->TeleportTo(530, -1841.091187f, 5384.616699f, -12.427767f, 2.012928f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 6: // Arena de Gurubashi
			plr->TeleportTo(0, -13225.893555f, 232.465149f, 33.310444f, 1.121269f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 77:
			if (plr->GetTeam() == ALLIANCE){
				
				plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Achievement_General_AllianceSlayer:30|t Stolen Treasure: АльянсГ§a", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
				plr->ADD_GOSSIP_ITEM(9, "|TInterface\\icons\\Achievement_BG_returnXflags_def_WSG:30|t Voltar", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 99);
			}
			else if (plr->GetTeam() == HORDE){
				plr->ADD_GOSSIP_ITEM(2, "|TInterface\\icons\\Achievement_General_HordeSlayer:30|t Stolen Treasure: Орда", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
				plr->ADD_GOSSIP_ITEM(9, "|TInterface\\icons\\Achievement_BG_returnXflags_def_WSG:30|t Voltar", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 99);
			}
			plr->SEND_GOSSIP_MENU(1, npc->GetGUID());
			break;

		case GOSSIP_ACTION_INFO_DEF + 8: // Pet Hunter Zone
			plr->TeleportTo(571, 7099.724609f, 2612.821289f, 1813.737305f, 5.646317f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 9: // Baradin Hold - Custom Raid
			plr->TeleportTo(732, -1254.219971f, 1050.030029f, 106.995003f, 3.150940f);
			break;

			//ALLIANCE TELEPORTERS_START
		case GOSSIP_ACTION_INFO_DEF + 10: // Stormwind teleport
			plr->TeleportTo(0, -8828.601563f, 627.279053f, 94.030663f, 3.924985f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 11: // Ironforge teleport
			plr->TeleportTo(0, -4918.879883f, -940.406006f, 504.854126f, 5.423470f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 12: // Darnassus Teleport
			plr->TeleportTo(1, 9949.559570f, 2284.20996f, 1342.969482f, 1.595870f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 13: // The Exodar Teleport
			plr->TeleportTo(530, -3965.699951f, -11653.599609f, -137.184998f, 0.852154f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 14: // Attack Orgrimmar
			plr->TeleportTo(1, 1025.285156f, -4439.764160f, 12.237539f, 0.178984f);
			break;

			//ALLIANCE TELEPORTERS_END

			//HORDE TELEPORTERS_START
		case GOSSIP_ACTION_INFO_DEF + 15: // Orgrimmar Teleport
			plr->TeleportTo(1, 1569.758789f, -4396.000977f, 16.890827f, 1.155946f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 16: // Undercity Teleport
			plr->TeleportTo(0, 1573.561279f, 240.414459f, -62.077351f, 0.033143f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 17: // Thunder Bluff Teleport
			plr->TeleportTo(1, -1297.956421f, 208.591827f, 68.681366f, 5.084499f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 18: // Silvermoon Teleport
			plr->TeleportTo(530, 9397.452148f, -7279.064941f, 14.216600f, 0.009944f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 19: // Attack Stormwind
			plr->TeleportTo(0, -9165.100586f, 465.795807f, 104.171112f, 5.289221f);
			break;
			//HORDE TELEPORTERS_END

		case GOSSIP_ACTION_INFO_DEF + 21: // Stolen Treasure: AlianГ§a
			plr->TeleportTo(1, -11143.608398f, -1439.585327f, 10.807365f, 1.050831f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 22: // Stolen Treasure: Horda
			plr->TeleportTo(1, -11109.398438f, -1549.427124f, 6.677382f, 1.066545f);
			break;

		case GOSSIP_ACTION_INFO_DEF + 99: // Close Function
			plr->CLOSE_GOSSIP_MENU();
			break;
		}
		return true;
	}
};
void AddSC_GossipNpc()
{
	new GossipNpc();
}
