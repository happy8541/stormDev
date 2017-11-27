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
#include <cstring>

class morphs_npc : public CreatureScript
{
public:
    morphs_npc() : CreatureScript("morphs_npc") {}

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->CLOSE_GOSSIP_MENU();	
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Человек(мужчина)", GOSSIP_SENDER_MAIN, 20);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Человек(женщина)", GOSSIP_SENDER_MAIN, 21);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Гном(мужчина)", GOSSIP_SENDER_MAIN, 22);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Гном(женщина)", GOSSIP_SENDER_MAIN, 23);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Эльф(мужчина)", GOSSIP_SENDER_MAIN, 24);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Эльф(женщина)", GOSSIP_SENDER_MAIN, 25);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Таурен(мужчина)", GOSSIP_SENDER_MAIN, 26);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Таурен(женщина)", GOSSIP_SENDER_MAIN, 27);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Дворф(мужчина)", GOSSIP_SENDER_MAIN, 36);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Дворф(женщина)", GOSSIP_SENDER_MAIN, 28);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Эльф(мужчина)", GOSSIP_SENDER_MAIN, 37);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Эльф(женщина)", GOSSIP_SENDER_MAIN, 29);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Орк(мужчина)", GOSSIP_SENDER_MAIN, 30);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Орк(женщина)", GOSSIP_SENDER_MAIN, 38);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Троль(мужчина)", GOSSIP_SENDER_MAIN, 39);
	    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Троль(женщина)", GOSSIP_SENDER_MAIN, 31);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Мужчина", GOSSIP_SENDER_MAIN, 32);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Женщина", GOSSIP_SENDER_MAIN, 33);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Дреней(мужчина)", GOSSIP_SENDER_MAIN, 40);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Дреней(женщина)", GOSSIP_SENDER_MAIN, 41);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Ворген(мужчина)", GOSSIP_SENDER_MAIN, 42);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Ворген(женщина)", GOSSIP_SENDER_MAIN, 43);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Гоблин(мужчина)", GOSSIP_SENDER_MAIN, 44);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Гоблин(женщина)", GOSSIP_SENDER_MAIN, 45);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Убрать морф", GOSSIP_SENDER_MAIN, 34);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Выход", GOSSIP_SENDER_MAIN, 35);
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        switch (action)
        {
			case 20:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(37925);
				break;
			case 21:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(37926);
				break;
			case 22:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(37913);
				break;
			case 23:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20581);
				break;
			case 24:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20578);
				break;
			case 25:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20579);
				break;
			case 26:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20585);
				break;
			case 27:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20584);
				break;
			case 28:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(37918);
				break;
			case 29:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(37919);
				break;
			case 30:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(37920);
				break;
			case 31:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(37922);
				break;
			case 32:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(37923);
				break;
			case 33:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(37924);
				break;
			case 34:
				player->CLOSE_GOSSIP_MENU();
				player->DeMorph();
				break;
			case 35:
				player->CLOSE_GOSSIP_MENU();
				break;
			case 36:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20317);
				break;
			case 37:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20318);
				break;
			case 38:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20316);
				break;
			case 39:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20321);
				break;
			case 40:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(37916);
				break;
			case 41:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20323);
				break;
			case 42:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(37915);
				break;
			case 43:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(37914);
				break;
			case 44:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20582);
				break;
			case 45:
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20583);
				break;
				
		case 46:
			OnGossipHello(player, creature);
			break;
		}
		
		return true;
	}
	
};

void AddSC_morphs_npc()
{
    new morphs_npc();
}