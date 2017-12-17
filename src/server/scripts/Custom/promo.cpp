/*промо сет штормскейл х7 или х100*/

#include "ScriptPCH.h"

class npc_promo_pve : public CreatureScript 

{
public:
    npc_promo_pve() : CreatureScript("npc_promo_pve") { } 
 
    bool OnGossipHello(Player* player, Creature* creature) 
    {
        player->ADD_GOSSIP_ITEM(7, "Escoge tu Set pve (solo puedes escoger pvp o pve): ", GOSSIP_SENDER_MAIN, 99);
		switch (player->getClass())
		{
				case CLASS_DRUID: player->ADD_GOSSIP_ITEM(10, "Set pve de Druida Equilibrio", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+30); player->ADD_GOSSIP_ITEM(10, "Set pve de Druida Feral", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+44); player->ADD_GOSSIP_ITEM(10, "Set pve de Druida Restauracion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+45); break;
				case CLASS_SHAMAN: player->ADD_GOSSIP_ITEM(10, "Set pve de Chaman Elemental", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+31); player->ADD_GOSSIP_ITEM(10, "Set pve de Chaman Mejora", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+46); player->ADD_GOSSIP_ITEM(10, "Set pve de Chaman Restauracion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+47); break;
				case CLASS_PALADIN: player->ADD_GOSSIP_ITEM(10, "Set pve de Paladin Represion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+32); player->ADD_GOSSIP_ITEM(10, "Set pve de Paladin Sagrado", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+40); player->ADD_GOSSIP_ITEM(10, "Set pve de Paladin Proteccion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+41); break;
				case CLASS_WARRIOR: player->ADD_GOSSIP_ITEM(10, "Set pve de Guerrero Furia", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+33); player->ADD_GOSSIP_ITEM(10, "Set pve de Guerrero Proteccion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+48); break;
				case CLASS_PRIEST: player->ADD_GOSSIP_ITEM(10, "Set pve de Sacerdote Sombras", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+34); player->ADD_GOSSIP_ITEM(10, "Set pve de Sacerdote Sagrado", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+42); break;
				case CLASS_DEATH_KNIGHT: player->ADD_GOSSIP_ITEM(10, "Set pve de DK DPS", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+35); player->ADD_GOSSIP_ITEM(10, "Set pve de DK Tank", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+43); break;
				case CLASS_ROGUE: player->ADD_GOSSIP_ITEM(10, "Set pve de Picaro", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+36); break;
				case CLASS_HUNTER: player->ADD_GOSSIP_ITEM(10, "Set pve de Cazador", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+37); break;
				case CLASS_MAGE: player->ADD_GOSSIP_ITEM(10, "Set pve de Mago", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+38); break;
				case CLASS_WARLOCK: player->ADD_GOSSIP_ITEM(10, "Set pve de Brujo", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+39); break;
		}
        player->SEND_GOSSIP_MENU(1, creature->GetGUID()); 
        return true;
    }
 
    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 actions)
    {
	    
		if (player->getLevel() == 85) 
		{
            player->GetSession()->SendAreaTriggerMessage("No puedes recibir la promocion mas de una vez.");
			player->CLOSE_GOSSIP_MENU();
			return true;
        }
		
        if (player->getLevel() == 1) 
        {
            uint32 accountID = player->GetSession()->GetAccountId();
            QueryResult result = CharacterDatabase.PQuery("SELECT COUNT(`guid`) FROM `characters` WHERE `account`=%u", accountID);
            Field *fields = result->Fetch();
            uint32 personajes = fields[0].GetUInt32();

            if (personajes == 1)		
                    {
					    if (actions == 99)
						{
						    player->CLOSE_GOSSIP_MENU();
						    return false;
						}
						player->GetSession()->SendAreaTriggerMessage("Has recibido tu promocion satisfactoriamente.");
                        player->GiveLevel(85);
						player->SetMoney(300000000);
						switch(actions)
                              {								  
								  case GOSSIP_ACTION_INFO_DEF+30: // Druida Equilibrio
								  player->AddItem(60290, 1);
								  player->AddItem(60289, 1);
								  player->AddItem(60288, 1);
								  player->AddItem(60287, 1);
								  player->AddItem(60286, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+44: // Druida Feral
								  player->AddItem(60290, 1);
								  player->AddItem(60289, 1);
								  player->AddItem(60288, 1);
								  player->AddItem(60287, 1);
								  player->AddItem(60286, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+45: // Druida Restauracion
								  player->AddItem(60276, 1);
								  player->AddItem(60277, 1);
								  player->AddItem(60278, 1);
								  player->AddItem(60279, 1);
								  player->AddItem(60280, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+31: // Chaman Elemental
								  player->AddItem(60317, 1);
								  player->AddItem(60316, 1);
								  player->AddItem(60315, 1);
								  player->AddItem(60314, 1);
								  player->AddItem(60313, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+46: // Chaman Mejora
								  player->AddItem(60322, 1);
								  player->AddItem(60321, 1);
								  player->AddItem(60320, 1);
								  player->AddItem(60319, 1);
								  player->AddItem(60318, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+47: // Chaman Restauracion
								  player->AddItem(60312, 1);
								  player->AddItem(60311, 1);
								  player->AddItem(60310, 1);
								  player->AddItem(60309, 1);
								  player->AddItem(60308, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+32: // Paladin Represion
								  player->AddItem(60344, 1);
								  player->AddItem(60345, 1);
								  player->AddItem(60346, 1);
								  player->AddItem(60347, 1);
								  player->AddItem(60348, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+40: // Paladin Tank Sagrado
								  player->AddItem(60363, 1);
								  player->AddItem(60362, 1);
								  player->AddItem(60361, 1);
								  player->AddItem(60360, 1);
								  player->AddItem(60359, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+41: // Paladin Healer Proteccion
								  player->AddItem(60344, 1);
								  player->AddItem(60345, 1);
								  player->AddItem(60346, 1);
								  player->AddItem(60347, 1);
								  player->AddItem(60348, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+33: // Guerrero Furia
								  player->AddItem(60323, 1);
								  player->AddItem(60324, 1);
								  player->AddItem(60325, 1);
								  player->AddItem(60326, 1);
								  player->AddItem(60327, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+48: // Guerrero Proteccion
								  player->AddItem(60328, 1);
								  player->AddItem(60329, 1);
								  player->AddItem(60330, 1);
								  player->AddItem(60331, 1);
								  player->AddItem(60332, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+34: // Sacerdote Sombras
								  player->AddItem(60257, 1);
								  player->AddItem(60256, 1);
								  player->AddItem(60255, 1);
								  player->AddItem(60254, 1);
								  player->AddItem(60253, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+42: // Sacerdote Sagrado
								  player->AddItem(60258, 1);
								  player->AddItem(60259, 1);
								  player->AddItem(60261, 1);
								  player->AddItem(60262, 1);
								  player->AddItem(60275, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+35: // DK DPS
								  player->AddItem(60339, 1);
								  player->AddItem(60340, 1);
								  player->AddItem(60341, 1);
								  player->AddItem(60342, 1);
								  player->AddItem(60343, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+43: // DK Tank
								  player->AddItem(60349, 1);
								  player->AddItem(60350, 1);
								  player->AddItem(60351, 1);
								  player->AddItem(60352, 1);
								  player->AddItem(60353, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;								  

								  case GOSSIP_ACTION_INFO_DEF+36: // Picaro
								  player->AddItem(60298, 1);
								  player->AddItem(60299, 1);
								  player->AddItem(60300, 1);
								  player->AddItem(60301, 1);
								  player->AddItem(60303, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+37: // Cazador
								  player->AddItem(60303, 1);
								  player->AddItem(60304, 1);
								  player->AddItem(60305, 1);
								  player->AddItem(60306, 1);
								  player->AddItem(60307, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+38: // Mago
								  player->AddItem(60243, 1);
								  player->AddItem(60244, 1);
								  player->AddItem(60245, 1);
								  player->AddItem(60246, 1);
								  player->AddItem(60247, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+39: // Brujo
								  player->AddItem(60248, 1);
								  player->AddItem(60249, 1);
								  player->AddItem(60250, 1);
								  player->AddItem(60252, 1);
								  player->AddItem(60253, 1);
								  player->AddItem(68008, 1);
								  player->AddItem(33809, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
	                          }
                    }			
			
			if (personajes > 1)
                    {
                        player->GetSession()->SendAreaTriggerMessage("No puedes recibir la promocion teniendo mas de un personaje.");
						player->CLOSE_GOSSIP_MENU();
						return true;
                    }
			
		    player->CLOSE_GOSSIP_MENU();
        }
        return true;
    }
};
 
void AddSC_npc_promo_pve() 
{
    new npc_promo_pve(); 
}