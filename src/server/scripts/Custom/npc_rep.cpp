/* ScriptData
SDName: npc_reputation
SD%Complete: 100%
SDComment: Wotlk/Cataclysm npc_reputation
SDCategory: Custom NPC Script
Stormscale.Ru WoW-emulator 4.3.4 cataclysm Main DEV Inc.
EndScriptData */

//Includes
#include "ScriptPCH.h"

//Define Spells
#define SPELL_REPUTATION    61456  //Only Visual Effect

class npc_reputation : public CreatureScript
{
    public:
        npc_reputation() : CreatureScript("npc_reputation") { }

                bool OnGossipHello(Player *player, Creature *_creature)
                {
                        if (player->IsInCombat())
                        {
                                player->CLOSE_GOSSIP_MENU();
                                _creature->MonsterWhisper("Вы находитесь в бою!" ,0 , player->GetGUID());
                        return true;
                        }
                else
                        {
                                player->ADD_GOSSIP_ITEM( 8, "Wrath of the Lich King "             , GOSSIP_SENDER_MAIN, 1);
                                player->ADD_GOSSIP_ITEM( 8, "Cataclysm "                           , GOSSIP_SENDER_MAIN, 2);
                        }

                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                return true;
                }

                bool GiveReputation(Player *player, unsigned int factionentry, unsigned int repAMOUNT)
                {
                        player->GetReputationMgr().GetReputation(sFactionStore.LookupEntry(factionentry) , repAMOUNT);
                        player->CastSpell(player,SPELL_REPUTATION,false);

                player->CLOSE_GOSSIP_MENU();
                return false;
                }

                bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
                {
                    if (player->IsInCombat())
                    {
                                player->CLOSE_GOSSIP_MENU();
                                _creature->MonsterWhisper("Вы находитесь в бою!" ,0 , player->GetGUID());
                                return true;
                   }
                    if (sender == GOSSIP_SENDER_MAIN)
                    {
                         player->PlayerTalkClass->ClearMenus();
                      switch(uiAction)
                         {
                         case 1: //Wrath of the Lich King
                            if ( player->GetTeam() == ALLIANCE ) //if alliance
                                {
                                        player->ADD_GOSSIP_ITEM( 3, "Alliance Vanguard"           , GOSSIP_SENDER_MAIN, 100);
                                        player->ADD_GOSSIP_ITEM( 3, "Explorers' League"           , GOSSIP_SENDER_MAIN, 101);
                                        player->ADD_GOSSIP_ITEM( 3, "The Frostborn"               , GOSSIP_SENDER_MAIN, 102);
                                        player->ADD_GOSSIP_ITEM( 3, "The Silver Covenant"         , GOSSIP_SENDER_MAIN, 103);
                                        player->ADD_GOSSIP_ITEM( 3, "Valiance Expedition"         , GOSSIP_SENDER_MAIN, 104);
                                }
                                else if ( player->GetTeam() == HORDE ) //if horde
                                {
                                        player->ADD_GOSSIP_ITEM( 3, "Horde Expedition"            , GOSSIP_SENDER_MAIN, 105);
                                        player->ADD_GOSSIP_ITEM( 3, "The Hand of Vengeance"       , GOSSIP_SENDER_MAIN, 106);
                                        player->ADD_GOSSIP_ITEM( 3, "The Sunreavers"              , GOSSIP_SENDER_MAIN, 107);
                                        player->ADD_GOSSIP_ITEM( 3, "The Taunka"                  , GOSSIP_SENDER_MAIN, 108);
                                        player->ADD_GOSSIP_ITEM( 3, "Warsong Offensive"           , GOSSIP_SENDER_MAIN, 109);
                                }
                                player->ADD_GOSSIP_ITEM( 3, "Argent Crusade"                      , GOSSIP_SENDER_MAIN, 110);
                                player->ADD_GOSSIP_ITEM( 3, "Frenzyheart Tribe"                   , GOSSIP_SENDER_MAIN, 111);
                                player->ADD_GOSSIP_ITEM( 3, "Kirin Tor"                           , GOSSIP_SENDER_MAIN, 112);
                                player->ADD_GOSSIP_ITEM( 3, "Knights of the Ebon Blade"           , GOSSIP_SENDER_MAIN, 113);
                                player->ADD_GOSSIP_ITEM( 3, "The Kalu'ak"                         , GOSSIP_SENDER_MAIN, 114);
                                player->ADD_GOSSIP_ITEM( 3, "The Oracles"                         , GOSSIP_SENDER_MAIN, 115);
                                player->ADD_GOSSIP_ITEM( 3, "The Sons of Hodir"                   , GOSSIP_SENDER_MAIN, 116);
                                player->ADD_GOSSIP_ITEM( 3, "The Wyrmrest Accord"                 , GOSSIP_SENDER_MAIN, 117);
                                player->ADD_GOSSIP_ITEM( 3, "The Ashen Verdict"                   , GOSSIP_SENDER_MAIN, 118);

                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                      , GOSSIP_SENDER_MAIN, 3);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                        break;

                         case 2: //Cataclysm
                            if ( player->GetTeam() == ALLIANCE ) //if alliance
                                {
                                        player->ADD_GOSSIP_ITEM( 3, "Baradin's Wardens"           , GOSSIP_SENDER_MAIN, 200);
                                        player->ADD_GOSSIP_ITEM( 3, "Wildhammer Clan"             , GOSSIP_SENDER_MAIN, 201);
                                }
                                else if ( player->GetTeam() == HORDE ) //if horde
                                {
                                        player->ADD_GOSSIP_ITEM( 3, "Dragonmaw Clan"              , GOSSIP_SENDER_MAIN, 202);
                                        player->ADD_GOSSIP_ITEM( 3, "Hellscream's Reach"          , GOSSIP_SENDER_MAIN, 203);
                                }
                                player->ADD_GOSSIP_ITEM( 3, "Guardians of Hyjal"                  , GOSSIP_SENDER_MAIN, 204);
                                player->ADD_GOSSIP_ITEM( 3, "Ramkahen"                            , GOSSIP_SENDER_MAIN, 205);
                                player->ADD_GOSSIP_ITEM( 3, "The Earthen Ring"                    , GOSSIP_SENDER_MAIN, 206);
                                player->ADD_GOSSIP_ITEM( 3, "Therazane"                           , GOSSIP_SENDER_MAIN, 207);
                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                      , GOSSIP_SENDER_MAIN, 3);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                               break;

                         case 3: //<- [Main Menu]
                                player->ADD_GOSSIP_ITEM( 8, "Wrath of the Lich King "             , GOSSIP_SENDER_MAIN, 1);
                                player->ADD_GOSSIP_ITEM( 8, "Cataclysm "                           , GOSSIP_SENDER_MAIN, 2);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                               break;

                         case 100: //hm
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                               return GiveReputation(player, 1037, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 101: //Explorers' League
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1068, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 102: //The Frostborn
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1126, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 103: //The Silver Covenant
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1094, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 104: //Valiance Expedition
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1050, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 105: //Horde Expedition
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1052, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 106: //The Hand of Vengeance
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1067, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 107: //The Sunreavers
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1124, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 108: //The Taunka
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1064, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 109: //Warsong Offensive
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1085, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 110: //Argent Crusade
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1106, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 111: //Frenzyheart Tribe
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1104, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 112: //Kirin Tor
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1090, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 113: //Knights of the Ebon Blade
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1098, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 114: //The Kalu'ak
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1073, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 115: //The Oracles
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1105, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 116: //The Sons of Hodir
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1119, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 117: //The Wyrmrest Accord
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1091, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 118: //The Ashen Verdict
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1156, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 98: //Baradin's Wardens
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1177, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 97: //Wildhammer Clan
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1174, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 202: //Dragonmaw Clan
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1172, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 203: //Hellscream's Reach
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1178, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 204: //Guardians of Hyjal
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1158, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 205: //Ramkahen
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1173, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 206: //The Earthen Ring
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1135, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 
break;
                         case 207: //Therazane
                                if (player->GetMoney() < 10000000)
                                {
                                _creature->MonsterWhisper("У Вас недостаточно золота." ,0 , player->GetGUID());
                                }
                                else
                                {
                                return GiveReputation(player, 1171, 90999);
                               player->ModifyMoney(-10000000);
                                _creature->MonsterWhisper("Репутация выдана, спасибо за покупку!" ,0 , player->GetGUID());
                                } 

break;
                         default:
                                 break;
                         }
                  }
                  return true;
          }
};

void AddSC_npc_reputation()
{
    new npc_reputation();
}
 