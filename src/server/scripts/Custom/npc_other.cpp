#include "ScriptPCH.h"
#include "ScriptMgr.h"

#define MSG_GOSSIP_TEXT_GETTING_STARTED "Добро пожаловать на сервер!"

#define MSG_ERR_AURA "Снятие дебафа 'Слабость после воскрешения' не возможна."
#define MSG_ERR_INCOMBAT "Вы находитесь в бою!"
#define MSG_ERR_ARENA_POINT "Необходимо больше Очков чести!"

#define MSG_COMPLETE_RENAME "Выйдите из игры и вам будет предложено сменить имя персонажу"
#define MSG_CUSTOMIZE_COMPLETE "Выйдите из игры и вам будет предложено сменить внешность вашего персонажа"
#define MSG_CHANGE_FACTION_COMPLETE "Выйдите из игры и вам будет предложено сменить фракцию вашего персонажа"

#define MSG_GOSSIP_TEXT_MAX_HEALTH "Излечи меня, мудрец!"
#define MSG_GOSSIP_TEXT_MAX_SKILL "Обучи меня навыкам владения оружием!"
#define MSG_GOSSIP_TEXT_UNAURA_ALL "Помоги мне избавиться от назойливой боли... Отчисти меня от порчи"
#define MSG_GOSSIP_TEXT_BAGS "Пожертвуй мне несколько больших мешков, старче"
#define MSG_GOSSIP_TEXT_RIDING "Обучи меня верховой езде..."

#define MSG_GOSSIP_TEXT_RENAME "Позволь мне сменить мое имя, я готов заплатить 100000 очков чести..."    // Thank Kim
#define MSG_GOSSIP_TEXT_CUSTOM "Измени мне внешность до неузнаваемости, я готов заплатить 150000 очков чести..." // Thank Kim
#define MSG_GOSSIP_TEXT_CHANGE_FACTION "Перевоплати меня в могучего война моего врага, я готов заплатить 250000 очков чести..."

#define MSG_GOSSIP_TEXT_A7_PRIEST_HEAL "Подари мне набор Жреца - Лекаря"
#define MSG_GOSSIP_TEXT_A7_PRIEST_DD "Подари мне набор Жреца - Мастера тьмы"
#define MSG_GOSSIP_TEXT_A7_DRUID_FERAL "Подари мне набор Друида - Силы зверя"
#define MSG_GOSSIP_TEXT_A7_DRUID_RESTOR "Подари мне набор Друида - Лекаря"
#define MSG_GOSSIP_TEXT_A7_DRUID_BALANSE "Подари мне набор Друида - Мастера баланса"
#define MSG_GOSSIP_TEXT_A7_WARRIOR "Подари мне набор Воина"
#define MSG_GOSSIP_TEXT_A7_MAGE "Подари мне набор Мага"
#define MSG_GOSSIP_TEXT_A7_HUNTER "Подари мне набор Охотника"
#define MSG_GOSSIP_TEXT_A7_PALLADIN_HOLI "Подари мне набор Паладина - Лекаря"
#define MSG_GOSSIP_TEXT_A7_PALLADIN_DD "Подари мне набор Паладина - Мастера молота"
#define MSG_GOSSIP_TEXT_A7_ROGUE "Подари мне набор Разбойника"
#define MSG_GOSSIP_TEXT_A7_DK "Подари мне набор Рыцаря Смерти"
#define MSG_GOSSIP_TEXT_A7_LOOK "Подари мне набор Чернокнижника"
#define MSG_GOSSIP_TEXT_A7_SHAMAN_HOLI "Подари мне набор Шамана - Лекаря" 
#define MSG_GOSSIP_TEXT_A7_SHAMAN_RDD "Подари мне набор Шамана - Повелителя стихий" 
#define MSG_GOSSIP_TEXT_A7_SHAMAN_DD "Подари мне набор Шамана - Мастера топора"
#define MSG_GOSSIP_TEXT_GIVE_DD "Подари мне набор для сокрушения монстров"
#define MSG_GOSSIP_TEXT_GIVE_HEAL "Подари мне набор для исцеления союзников"
#define MSG_GOSSIP_TEXT_GIVE_TANK "Подари мне набор для удержания монстров"

#define CONST_ARENA_POINT_1 1000
#define CONST_ARENA_POINT_2 3000


		  int bag = 38082;
		  int warlockItem[5] =                    {41993,41998,42005,42011,42017};
		  int warlockTItem[5] = 			{46140,46136,46137,46135,46139};
                int warriorItem[5] =                    {40826,40866,40789,40807,40847};
		  int warriorTDDItem[5] = 			{46151,46149,46146,46148,46150};
		  int warriorTTankItem[5] = 		{46166,46167,46162,46164,46169};
                int druidRestorItem[5] =                {41321,41275,41310,41287,41298};
		  int druidTRestorItem[5] = 		{46184,46187,46186,46183,46185};
                int druidBalanceItem[5] =               {41327,41281,41316,41293,41304};
                int druidTBalanceItem[5] =              {46191,46196,46194,46189,46192};
                int druidFeralItem[5] =                 {41678,41715,41661,41773,41667};
                int druidTFeralItem[5] =                {46161,46157,46159,46158,46160};
                int priestDiscItem[5] =                 {41854,41869,41859,41874,41864};
                int priestTDiscItem[5] =                {46197,46190,46193,46188,46195};
                int priestShadowItem[5] =               {41915,41934,41921,41940,41927};
                int priestTShadowItem[5] =               {46172,46165,46168,46163,46170};
                int mageItem[5] =                               {41946,41965,41953,41971,41959};
                int mageTItem[5] =                               {46129,46134,46130,46132,46133};
                int hunterItem[5] =                             {41157,41217,41087,41143,41205};
                int hunterTItem[5] =                             {46143,46145,46141,46142,46144};
                int paladinHolyItem[5] =                {40933,40963,40907,40927,40939};
                int paladinTHolyItem[5] =                {46180,46182,46178,48179,46181};
                int paladinMeleeItem[5] =               {40828,40869,40788,40808,40849};
                int paladinTMeleeItem[5] =               {46156,46152,46154,46155,46153};
                int paladinTProtoItem[5] =               {46175,46177,46173,46174,46176};
                int rogueItem[5] =                              {41672,41683,41650,41767,41655};
                int rogueTItem[5] =                              {46125,46127,46123,46124,46126};
                int deathknightItem[5] =                {40827,40868,40787,40809,40848};
                int deathknightTDDItem[5] =                {46115,46117,46111,46113,46116};
                int deathknightTTankItem[5] =                {46120,46122,46118,46119,46121};
                int shamanMeleeItem[5] =                {41151,41211,41081,41137,41199};
                int shamanElementalItem[5] =    {41019,41044,40993,41007,41033};
                int shamanRestorItem[5] =               {41013,41038,40992,41001,41027};
                int shamanTMeleeItem[5] =                {46212,46203,46205,46200,46208};
                int shamanTElementalItem[5] =    {46209,46209,46206,46207,46210};
                int shamanTRestorItem[5] =               {46201,46204,46198,46199,46202};

class npc_other : public CreatureScript
{
    public: 
    npc_other() : CreatureScript("npc_other") { }

        void AddSet(Player* player, int massive[5])
        {
                for (int i = 0; i < 5; ++i)
                        {
                                player->AddItem(massive[i], 1);
                        }
                player->CLOSE_GOSSIP_MENU();
        }

        bool OnGossipHello(Player *player, Creature *_creature)
                { 
        //_creature->MonsterWhisper(MSG_GOSSIP_TEXT_GETTING_STARTED, player->GetGUID());
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR , MSG_GOSSIP_TEXT_BAGS, GOSSIP_SENDER_MAIN, 2);
                int playerClass = player->getClass();
                switch (playerClass)
                {
                case CLASS_WARLOCK:
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_LOOK, GOSSIP_SENDER_MAIN, 7);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_DD, GOSSIP_SENDER_MAIN, 26);
                break;
                case CLASS_WARRIOR:
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_WARRIOR, GOSSIP_SENDER_MAIN, 8);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_DD, GOSSIP_SENDER_MAIN, 27);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_TANK, GOSSIP_SENDER_MAIN, 28);
                break;
                case CLASS_DRUID:
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_DRUID_RESTOR, GOSSIP_SENDER_MAIN, 9);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_DRUID_BALANSE, GOSSIP_SENDER_MAIN, 10);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_DRUID_FERAL, GOSSIP_SENDER_MAIN, 11);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_DD, GOSSIP_SENDER_MAIN, 29);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_HEAL, GOSSIP_SENDER_MAIN, 30);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_TANK, GOSSIP_SENDER_MAIN, 31);
                break;
                case CLASS_PRIEST:
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_PRIEST_HEAL, GOSSIP_SENDER_MAIN, 12);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_PRIEST_DD, GOSSIP_SENDER_MAIN, 13);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_DD, GOSSIP_SENDER_MAIN, 32);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_HEAL, GOSSIP_SENDER_MAIN, 33);
                break;
                case CLASS_MAGE:
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_MAGE, GOSSIP_SENDER_MAIN, 14);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_DD, GOSSIP_SENDER_MAIN, 34);
                break;
                case CLASS_PALADIN:
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_PALLADIN_HOLI, GOSSIP_SENDER_MAIN, 15);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_PALLADIN_DD, GOSSIP_SENDER_MAIN, 16);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_DD, GOSSIP_SENDER_MAIN, 35);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_HEAL, GOSSIP_SENDER_MAIN, 36);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_TANK, GOSSIP_SENDER_MAIN, 37);
                break;
                case CLASS_ROGUE:
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_ROGUE, GOSSIP_SENDER_MAIN, 17);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_DD, GOSSIP_SENDER_MAIN, 38);
                break;
                case CLASS_DEATH_KNIGHT:
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_DK, GOSSIP_SENDER_MAIN, 18);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_DD, GOSSIP_SENDER_MAIN, 39);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_TANK, GOSSIP_SENDER_MAIN, 40);
                break;
                case CLASS_SHAMAN:
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_SHAMAN_DD, GOSSIP_SENDER_MAIN, 19);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_SHAMAN_RDD, GOSSIP_SENDER_MAIN, 20);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_SHAMAN_HOLI, GOSSIP_SENDER_MAIN, 21);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_DD, GOSSIP_SENDER_MAIN, 41);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Подари мне набор для убийства монстров на расстоянии", GOSSIP_SENDER_MAIN, 42);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_HEAL, GOSSIP_SENDER_MAIN, 43);
                break;
                case CLASS_HUNTER:
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_HUNTER, GOSSIP_SENDER_MAIN, 22);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_GIVE_DD, GOSSIP_SENDER_MAIN, 44);
                break;
                }
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MAX_HEALTH, GOSSIP_SENDER_MAIN, 3);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MAX_SKILL, GOSSIP_SENDER_MAIN, 4);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_UNAURA_ALL, GOSSIP_SENDER_MAIN, 5);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_RIDING, GOSSIP_SENDER_MAIN, 6);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_RENAME, GOSSIP_SENDER_MAIN, 23);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_CUSTOM, GOSSIP_SENDER_MAIN, 24);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_CHANGE_FACTION, GOSSIP_SENDER_MAIN, 25);
            player->SEND_GOSSIP_MENU (DEFAULT_GOSSIP_MESSAGE,_creature->GetGUID()); 
        return true;
        }


      bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 action )
                {
                  if (!player->getAttackers().empty())
        {
                //_creature->MonsterWhisper(MSG_ERR_INCOMBAT, player->GetGUID());
                player->CLOSE_GOSSIP_MENU();
        return false;
                  }
                  switch (action)
        {
                  case 2:
                         player->AddItem(bag, 4);
                         player->CLOSE_GOSSIP_MENU();
                         break;
                  case 3:
                          player->SetHealth(player->GetMaxHealth());
                      player->CLOSE_GOSSIP_MENU();
                          break;
                  case 4:
                          player->UpdateSkillsToMaxSkillsForLevel();
                      player->CLOSE_GOSSIP_MENU();
                          break;
                  case 5:
                         if (player->HasAura(15007))
                         {
                //_creature->MonsterWhisper(MSG_ERR_AURA, player->GetGUID());
                player->CLOSE_GOSSIP_MENU();
                }else
                        {
        player->RemoveAllAuras();
                player->CLOSE_GOSSIP_MENU();
                player->RemoveAllSpellCooldown();
                }
                      break;
                  case 6:
                          player->learnSpell(90265, true);
                      player->SetSkill(762, 6, 450, 450);
                      player->learnSpell(54197, true);
                      player->CLOSE_GOSSIP_MENU();
                          break;
                  case 7:
                          AddSet(player, warlockItem);
                          player->CLOSE_GOSSIP_MENU();
                          break;
                  case 8:
						  player->learnSpell(750, true);
                          AddSet(player, warriorItem);
                          break;
                  case 9:
              AddSet(player, druidRestorItem);
                          break;
                  case 10:
                          AddSet(player, druidBalanceItem);
                          break;
                  case 11:
                          AddSet(player, druidFeralItem);
                          break;
                  case 12:
                          AddSet(player, priestDiscItem);
                          break;
                  case 13:
                          AddSet(player,  priestShadowItem);
                          break;
                  case 14:
                          AddSet(player,  mageItem);
                          break;
                  case 15:
				          player->learnSpell(750, true);
                          AddSet(player,  paladinHolyItem);
                          break;
                  case 16:
						  player->learnSpell(750, true);
                          AddSet(player,  paladinMeleeItem);
                          break;
                  case 17:
                          AddSet(player, rogueItem);
                          break;
                  case 18:
                          AddSet(player, deathknightItem);
                          break;
                  case 19:
						  player->learnSpell(8737, true);	
                          AddSet(player, shamanMeleeItem);
                          break;
                  case 20:
						  player->learnSpell(8737, true);
                          AddSet(player, shamanRestorItem);
                          break;
                  case 21:
						  player->learnSpell(8737, true);
                          AddSet(player, shamanElementalItem);
                          break;
                  case 22:
						  player->learnSpell(8737, true);
                          AddSet(player, hunterItem);
                          break;
		    /*case 23:
                if (player->GetHonorPoints() < 100000)
                {
                          _//creature->MonsterWhisper(MSG_ERR_ARENA_POINT, player->GetGUID());
                  player->CLOSE_GOSSIP_MENU();
                }else{
                      // Делаем Ренейм
                      player->SetAtLoginFlag(AT_LOGIN_RENAME);
                      player->ModifyCurrency(-100000);
              //_creature->MonsterWhisper(MSG_COMPLETE_RENAME, player->GetGUID());
              player->CLOSE_GOSSIP_MENU();
                      }
                      break;
                  case 24:
                          if (player->GetHonorPoints() < 150000)
                          {
                      //_creature->MonsterWhisper(MSG_ERR_ARENA_POINT, player->GetGUID());
                      player->CLOSE_GOSSIP_MENU();
            }else{
                      // Делаем Смену внешности
                      player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
                      //player->ModifyHonorPoints(-150000);
                      player->ModifyCurrency(-150000);
             // _creature->MonsterWhisper(MSG_CUSTOMIZE_COMPLETE, player->GetGUID());
              player->CLOSE_GOSSIP_MENU();
                          }
                          break;
                  case 25:
                          if (player->GetHonorPoints() < 250000)
                          {
                       //_creature->MonsterWhisper(MSG_ERR_ARENA_POINT, player->GetGUID());
                       player->CLOSE_GOSSIP_MENU();
             }else{
                       // Делаем Смену фракции
                       player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
                       player->ModifyCurrency(-250000);
               //_creature->MonsterWhisper(MSG_CHANGE_FACTION_COMPLETE, player->GetGUID());
               player->CLOSE_GOSSIP_MENU();
                          }
                          break;*/
				case 26 :
				AddSet(player, warlockTItem);
				break;
				case 27 :
				player->learnSpell(750, true);
				AddSet(player, warriorTDDItem);
				break;
				case 28 :
				player->learnSpell(750, true);
				AddSet(player, warriorTTankItem);
				break;
				case 29 :
				AddSet(player, druidTBalanceItem);
				break;
				case 30 :
				AddSet(player, druidTRestorItem);
				break;
				case 31 :
				AddSet(player, druidTFeralItem);
				break;
				case 32 :
				AddSet(player, priestTShadowItem);
				break;
				case 33 :
				AddSet(player, priestTDiscItem);
				break;
				case 34 :
				AddSet(player, mageTItem);
				break;
				case 35 :
				player->learnSpell(750, true);
				AddSet(player, paladinTMeleeItem);
				break;
				case 36 :
				player->learnSpell(750, true);
				AddSet(player, paladinTHolyItem);
				break;
				case 37 :
				player->learnSpell(750, true);
				AddSet(player, paladinTProtoItem);
				break;
				case 38 :
				AddSet(player, rogueTItem);
				break;
				case 39 :
				AddSet(player, deathknightTDDItem);
				break;
				case 40 :
				AddSet(player, deathknightTTankItem);
				break;
				case 41 :
				player->learnSpell(8737, true);
				AddSet(player, shamanTMeleeItem);
				break;
				case 42 :
				player->learnSpell(8737, true);
				AddSet(player, shamanTElementalItem);
				break;
				case 43 :
				player->learnSpell(8737, true);
				AddSet(player, shamanTRestorItem);
				break;
				case 44 :
				player->learnSpell(8737, true);
				AddSet(player, hunterTItem);
				break;
}
      return true;
}
          };

          void AddSC_npc_other()
{
        new npc_other;
}
