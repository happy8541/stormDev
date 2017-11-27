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

#include "ScriptPCH.h"
 
struct Rochet2
{
  uint8 icon;
	std::string name;
	uint32 HK, titleID;
};
 
//	{icon, "title name", honored_kills, titleID}
Rochet2 Titles [] =
{
	{9,		"|TInterface/PvPRankBadges/PvPRank01:20:20|t Private",					50,			1	},
	{9,		"|TInterface/PvPRankBadges/PvPRank02:20:20|t Corporal",					100,		2	},
	{9,		"|TInterface/PvPRankBadges/PvPRank03:20:20|t Sergeant",					250,		3	},
	{9,		"|TInterface/PvPRankBadges/PvPRank04:20:20|t Master Sergeant",			500,		4	},
	{9,		"|TInterface/PvPRankBadges/PvPRank05:20:20|t Sergeant Major",			750,		5	},
	{9,		"|TInterface/PvPRankBadges/PvPRank06:20:20|t Knight",					1000,		6	},
	{9,		"|TInterface/PvPRankBadges/PvPRank07:20:20|t Knight-Lieutenant",		1500,		7	},
	{9,		"|TInterface/PvPRankBadges/PvPRank08:20:20|t Knight-Captain",			2000,		8	},
	{9,		"|TInterface/PvPRankBadges/PvPRank09:20:20|t Knight-Champion",			2500,		9	},
	{9,		"|TInterface/PvPRankBadges/PvPRank10:20:20|t Lieutenant Commander",		3000,		10	},
	{9,		"|TInterface/PvPRankBadges/PvPRank11:20:20|t Commander",				3500,		11	},
	{9,		"|TInterface/PvPRankBadges/PvPRank12:20:20|t Marshal",					4000,		12	},
	{9,		"|TInterface/PvPRankBadges/PvPRank13:20:20|t Field Marshal",			4500,		13	},
	{9,		"|TInterface/PvPRankBadges/PvPRank14:20:20|t Grand Marshal",			5000,		14	},
 
	{9,		"|TInterface/PvPRankBadges/PvPRank01:20:20|t Scout",					50,		    15	},
	{9,		"|TInterface/PvPRankBadges/PvPRank02:20:20|t Grunt",					100,		16	},
	{9,		"|TInterface/PvPRankBadges/PvPRank03:20:20|t Sergeant",					250,		17	},
	{9,		"|TInterface/PvPRankBadges/PvPRank04:20:20|t Senior Sergeant",			500,		18	},
	{9,		"|TInterface/PvPRankBadges/PvPRank05:20:20|t First Sergeant",			750,		19	},
	{9,		"|TInterface/PvPRankBadges/PvPRank06:20:20|t Stone Guard",				1000,		20	},
	{9,		"|TInterface/PvPRankBadges/PvPRank07:20:20|t Blood Guard",				1500,		21	},
	{9,		"|TInterface/PvPRankBadges/PvPRank08:20:20|t Legionnaire",				2000,		22	},
	{9,		"|TInterface/PvPRankBadges/PvPRank09:20:20|t Centurion",				2500,		23	},
	{9,		"|TInterface/PvPRankBadges/PvPRank10:20:20|t Champion",					3000,		24	},
	{9,		"|TInterface/PvPRankBadges/PvPRank11:20:20|t Lieutenant General",		3500,		25	},
	{9,		"|TInterface/PvPRankBadges/PvPRank12:20:20|t General",					4000,		26	},
	{9,		"|TInterface/PvPRankBadges/PvPRank13:20:20|t Warlord",					4500,		27	},
	{9,		"|TInterface/PvPRankBadges/PvPRank14:20:20|t High Warlord",				5000,		28	},
};
 
enum eEnums
{
	Amount	=	sizeof Titles/sizeof(*Titles),
 
	// npc_text ID
	Greetings_A	=	1,
	Greetings_H	=	2,
};
 
#define ERROR_HASTITLE	"|cffff0000Você já tem esse Título!" // Error message that shows up when a player already has the title
#define ERROR_CASH "|cffff0000Você não tem honorable kills suficiente. Volte quando tiver!"
 
 
class Title_gossip_codebox : public CreatureScript
{
	public:
	Title_gossip_codebox()
	: CreatureScript("Title_gossip_codebox")
	{
	}
 
	bool OnGossipHello(Player* pPlayer, Creature* pCreature)
	{
		uint32 txt	= Greetings_A;
		uint32 i	= 0;
		uint32 m	= Amount/2;
		if(pPlayer->GetTeam() == HORDE)
		{
			txt = Greetings_H;
			i = Amount/2;
			m = Amount;
		}
		for (i; i<m; i++)
		{
			std::ostringstream ss;
			ss << Titles[i].name << " - " << Titles[i].HK << " Honorable Kills";
			std::string showcoolshit = ss.str();
			ss.clear();
			ss << "Será concedido o Titulo" << Titles[i].name;
			std::string showcoolshit2 = ss.str();
			// ADD_GOSSIP_ITEM_EXTENDED Parameters: (icon, label, GOSSIP_SENDER_MAIN (Sender), Title ID ? (action), popup, coppercost, code (false))
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(Titles[i].icon, showcoolshit.c_str(), GOSSIP_SENDER_MAIN, i, showcoolshit2, 0, false);
		}
		pPlayer->PlayerTalkClass->SendGossipMenu(txt, pCreature->GetGUID());
		return true;
	}
 
	bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 i)
	{
		pPlayer->PlayerTalkClass->ClearMenus(); // clear the menu
 
		if (CharTitlesEntry const* Title = sCharTitlesStore.LookupEntry(Titles[i].titleID)) // Get title
		{
			if(pPlayer->HasTitle(Title)) // If has title
				pPlayer->GetSession()->SendAreaTriggerMessage(ERROR_HASTITLE);
			else if(Titles[i].HK > pPlayer->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS)) // If doesnt have enough honored kills
				pPlayer->GetSession()->SendAreaTriggerMessage(ERROR_CASH);
			else
			{
				pPlayer->SetTitle(Title);
				pPlayer->SaveToDB();
			}
			OnGossipHello(pPlayer, pCreature);
		}
		return true;
	}
};
 
void AddSC_Title_gossip_codebox()
{
    new Title_gossip_codebox();
}