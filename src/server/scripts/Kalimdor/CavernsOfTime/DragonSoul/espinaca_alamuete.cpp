/*
Hecho 100% por BoT para BoT WoW.
No seais hijos de puta y lo useis sin mi permiso, gracias.
*/


#include "ScriptPCH.h"
#include "dragon_soul.h"
#include "Vehicle.h"
#include "InstanceScript.h"
#include "Map.h"
#include "AchievementMgr.h"
#include "Chat.h"
#include "Language.h"
#include "Player.h"
#include "ScriptMgr.h"

enum Events
{
	// Deathwing
	EVENT_SUM_TENTACULOS,
	EVENT_SUM_ADS,
	EVENT_SUM_TENTACULOS_1,	
	EVENT_SUM_TENDONES,	
	SPELL_AGARRE_IGNEO,
	EVENT_ELEMENTIUM_BOLT,
};

enum Spells
{
};

enum Texts
{
};

class npc_tendones : public CreatureScript
{
    public:
        npc_tendones() : CreatureScript("npc_tendones") { }

                CreatureAI* GetAI(Creature* creature) const
                {
                    return GetDragonSoulAI<npc_tendonesAI>(creature);
                }

                struct npc_tendonesAI : public BossAI
                {
                    npc_tendonesAI(Creature* creature) : BossAI(creature, BOSS_DEATHWING)
                    {
                        instance = creature->GetInstanceScript();
                    }

                        InstanceScript* instance;
                        EventMap events;
						
                        void Reset()
                        {
                            events.Reset();
                            me->SetInCombatWithZone();
							_Reset();
                        }
						
						void EnterEvadeMode()
						{
							Reset();
							DespawnCreatures(53891);
							DespawnCreatures(56341);
							DespawnCreatures(56575);
							DespawnCreatures(50223);
							DespawnCreatures(50237);
							me->SummonCreature(56341, -13854.50f, -13647.90f, 266.86f, 4.64f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							if (GameObject* placa1 = me->FindNearestGameObject(209631, 100.0f))
							{
								placa1->setActive(true);
							}
							if (GameObject* placa2 = me->FindNearestGameObject(209632, 100.0f))
							{
								placa2->setActive(true);
							}	
							if (GameObject* placa3 = me->FindNearestGameObject(209623, 100.0f))
							{
								placa3->setActive(true);
							}
							_EnterEvadeMode();
						}
						
                        void EnterCombat(Unit* /*who*/)
                        {				
							events.ScheduleEvent(EVENT_SUM_TENTACULOS_1, urand(5000, 5000));						
						}
						void DespawnCreatures(uint32 entry)
						{
							std::list<Creature*> creatures;
							GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);
				
							if (creatures.empty())
							return;
				
							for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
								(*iter)->DespawnOrUnsummon();
						}
						
               void UpdateAI(uint32 const diff)
				{
					if (!UpdateVictim())
                    return;
					
                    events.Update(diff);
					DoMeleeAttackIfReady();	
						
					while (uint32 eventId = events.ExecuteEvent())
					{
						switch (eventId)
						{
							case EVENT_SUM_TENTACULOS:
							/*me->SummonCreature(53891, -13854.81, -13592, 275.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13867.81, -13653, 263.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13687.81, -13638, 264.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13870.81, -13613, 267.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13871.81, -13596, 269.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13837.81, -13596, 268, 3.08f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13839.81, -13614, 266.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13840.81, -13634, 265.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13842.81, -13654, 263, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13841.81, -13666, 261.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							events.ScheduleEvent(EVENT_SUM_ADS, urand(10000,50000));
							events.ScheduleEvent(EVENT_SUM_TENTACULOS, urand(60000,60000));*/
							break;
							
							case EVENT_SUM_TENDONES:
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}		
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
							break;
							
							case EVENT_SUM_ADS:							
							me->SummonCreature(53889, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53889, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							if(IsHeroic())
							{
								me->SummonCreature(53889, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
								me->SummonCreature(53889, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}	
							events.ScheduleEvent(EVENT_SUM_ADS, urand(15000,30000));							
							break;		
								
							case EVENT_SUM_TENTACULOS_1:
							DespawnCreatures(53891);	
							//Tentaculos en la primera fase
							me->SummonCreature(53891, -13868.81f, -13667, 263.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13867.81f, -13653, 263.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13687.81f, -13638, 264.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);		
							me->SummonCreature(53891, -13842.81f, -13654, 263, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);	
							me->SummonCreature(53891, -13841.81f, -13666, 261.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);										
							//Tentaculos en fase placa 2
							if (me->FindNearestCreature(50223, 100.0f))
							{	
								me->SummonCreature(53891, -13867.61f, -13637.47f, 264.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
								me->SummonCreature(53891, -13840.81f, -13634, 265.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							//Tentaculos en fase placa 3
							if (me->FindNearestCreature(50237, 100.0f))
							{
								me->SummonCreature(53891, -13839.81f, -13614, 266.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);								
								me->SummonCreature(53891, -13870.81f, -13613, 267.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							
							events.CancelEvent(EVENT_SUM_ADS);
							events.ScheduleEvent(EVENT_SUM_ADS, urand(15000,30000));
							events.ScheduleEvent(EVENT_SUM_TENTACULOS_1, urand(60000,120000));
							break;							
							
						}
					}	
                 }

               void JustDied(Unit* /*Killer*/)
               {
			   		if (me->FindNearestCreature(50223, 100.0f))
					{
						DespawnCreatures(53891);
						events.CancelEvent(EVENT_SUM_TENTACULOS_1);
						if (GameObject* placa2 = me->FindNearestGameObject(209631, 100.0f))
						{
							placa2->SetGoState(GO_STATE_ACTIVE);
							me->SummonCreature(56575, -13854.73f, -13612.98f, 270.34f, 4.69f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
						}					
					}			   
			   		if (!me->FindNearestCreature(50223, 100.0f))
					{	
						DespawnCreatures(53891);
						events.CancelEvent(EVENT_SUM_TENTACULOS_1);
						me->SummonCreature(50223, -13854.73f, -13626.98f, 268.34f, 4.69f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
						if (GameObject* placa1 = me->FindNearestGameObject(209623, 100.0f))
						{
							placa1->SetGoState(GO_STATE_ACTIVE);
							me->SummonCreature(56341, -13854.73f, -13629.98f, 268.34f, 4.69f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
						}
					}
					me->DespawnOrUnsummon(5000);
					return;
				}
      };
};

class npc_tendones_2 : public CreatureScript
{
    public:
        npc_tendones_2() : CreatureScript("npc_tendones_2") { }

                CreatureAI* GetAI(Creature* creature) const
                {
                    return GetDragonSoulAI<npc_tendones_2AI>(creature);
                }

                struct npc_tendones_2AI : public BossAI
                {
                    npc_tendones_2AI(Creature* creature) : BossAI(creature, BOSS_DEATHWING)
                    {
                        instance = creature->GetInstanceScript();
                    }

                        InstanceScript* instance;
                        EventMap events;
						
                        void Reset()
                        {
                            events.Reset();
                            me->SetInCombatWithZone();
							_Reset();						
                        }

                        void EnterCombat(Unit* /*who*/)
                        {
							events.CancelEvent(EVENT_SUM_TENTACULOS_1);
							events.ScheduleEvent(EVENT_SUM_TENTACULOS_1, urand(5000, 5000));
						}
						
						void DespawnCreatures(uint32 entry)
						{
							std::list<Creature*> creatures;
							GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);
				
							if (creatures.empty())
							return;
				
							for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
								(*iter)->DespawnOrUnsummon();
						}
						
                void UpdateAI(uint32 const diff)
				{
					if (!UpdateVictim())
                    return;
					
                    events.Update(diff);
					DoMeleeAttackIfReady();
					
					while (uint32 eventId = events.ExecuteEvent())
					{
						switch (eventId)
						{
							case EVENT_SUM_TENTACULOS:
							/*me->SummonCreature(53891, -13854.81, -13592, 275.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13867.81, -13653, 263.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13687.81, -13638, 264.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13870.81, -13613, 267.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13871.81, -13596, 269.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13837.81, -13596, 268, 3.08f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13839.81, -13614, 266.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13840.81, -13634, 265.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13842.81, -13654, 263, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13841.81, -13666, 261.72, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							events.ScheduleEvent(EVENT_SUM_ADS, urand(10000,50000));
							events.ScheduleEvent(EVENT_SUM_TENTACULOS, urand(60000,60000));*/
							break;
							
							case EVENT_SUM_TENDONES:
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}		
								if (Creature* tentaculo = me->FindNearestCreature(53891, 100.0f, true))
								{
									tentaculo->DespawnOrUnsummon(5000);
								}
							break;
							
							case EVENT_SUM_ADS:							
							me->SummonCreature(53889, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53889, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							if(IsHeroic())
							{
								me->SummonCreature(53889, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
								me->SummonCreature(53889, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							events.ScheduleEvent(EVENT_SUM_ADS, urand(15000,30000));							
							break;		
								
							case EVENT_SUM_TENTACULOS_1:
							DespawnCreatures(53891);	
							//Tentaculos en la primera fase
							me->SummonCreature(53891, -13868.81f, -13667, 263.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13867.81f, -13653, 263.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							me->SummonCreature(53891, -13687.81f, -13638, 264.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);		
							me->SummonCreature(53891, -13842.81f, -13654, 263, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);	
							me->SummonCreature(53891, -13841.81f, -13666, 261.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);										
							//Tentaculos en fase placa 1
							if (me->FindNearestCreature(56575, 100.0f))
							{	
								me->SummonCreature(53891, -13867.61f, -13637.47f, 264.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
								me->SummonCreature(53891, -13840.81f, -13634, 265.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							//Tentaculos en fase placa 2
							if (me->FindNearestCreature(56575, 100.0f))
							{
								me->SummonCreature(53891, -13839.81f, -13614, 266.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);								
								me->SummonCreature(53891, -13870.81f, -13613, 267.72f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							if (me->FindNearestCreature(56575, 100.0f) && me->FindNearestCreature(50237, 100.0f))
							{
								me->SummonCreature(53891, -13827.77f, -13596.21, 268.40f, 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);								
								me->SummonCreature(53891, -13871.78f, -13596.76f, 269.12f, 6.13f, TEMPSUMMON_CORPSE_DESPAWN, 120000);							
							}
							
							events.CancelEvent(EVENT_SUM_ADS);
							events.ScheduleEvent(EVENT_SUM_ADS, urand(20000,40000));
							events.ScheduleEvent(EVENT_SUM_TENTACULOS_1, urand(60000,120000));
							break;							
							
						}
					}			
                 }

               void JustDied(Unit* /*Killer*/)
               {
					events.CancelEvent(EVENT_SUM_TENTACULOS_1);
			   		if (me->FindNearestCreature(50237, 100.0f))
					{
						std::list<Player*> TargetList;
						Map::PlayerList const& Players = me->GetMap()->GetPlayers();
						for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
						{	
							if (Player* player = itr->GetSource())
							{
								if (AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(6115))
									if(IsHeroic())
										player->CompletedAchievement(achievementEntry);
							}	
						}					
						me->DespawnOrUnsummon(5000);
						DespawnCreatures(53891);
						me->DespawnOrUnsummon(5000);
						me->SummonCreature(140003, -13854.73f, -13591.98f, 272.34f, 4.73f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
						if(Unit* killer = me->FindNearestPlayer(1000.0f))
							killer->SummonGameObject(RAID_MODE(209894, 209895, 209896, 209897), -12133.66f,  12076.17f, 2.30f, 3.57793f, 0.0f, 0.0f, -0.976295f, 0.216442f, 320000);

					}							
			   		if (!me->FindNearestCreature(50237, 100.0f))
					{					
						if (GameObject* placa3 = me->FindNearestGameObject(209632, 100.0f))
						{
							DespawnCreatures(53891);
							me->SummonCreature(50237, -13854.73f, -13626.98f, 268.34f, 4.69f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							placa3->SetGoState(GO_STATE_ACTIVE);
							me->SummonCreature(56575, -13854.73f, -13591.98f, 272.34f, 4.69f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
						}
					}			
				}
      };
};

class npc_tendones_3 : public CreatureScript
{
    public:
        npc_tendones_3() : CreatureScript("npc_tendones_3") { }

                CreatureAI* GetAI(Creature* creature) const
                {
                    return GetDragonSoulAI<npc_tendones_3AI>(creature);
                }

                struct npc_tendones_3AI : public ScriptedAI
                {
                    npc_tendones_3AI(Creature* creature) : ScriptedAI(creature)
                    {
                        instance = creature->GetInstanceScript();
                    }

                        InstanceScript* instance;
                        EventMap events;
						
                        void Reset()
                        {
                            events.Reset();
                            me->SetInCombatWithZone();
                        }

                        void EnterCombat(Unit* /*who*/)
                        {
						}

               void UpdateAI(uint32 const diff)
				{
					if (!UpdateVictim())
                    return;
					
                    events.Update(diff);
					DoMeleeAttackIfReady();
                 }

               void JustDied(Unit* /*Killer*/)
               {
			   		/*			me->DespawnOrUnsummon(5000);
					events.CancelEvent(EVENT_SUM_TENDONES);
					events.ScheduleEvent(EVENT_SUM_TENDONES, urand(2000,2000));
					DespawnCreatures(53891);
					DespawnCreatures(53889);
					DespawnCreatures(53890);	
					me->DespawnOrUnsummon(5000);
					DespawnCreatures(53891);
					events.CancelEvent(EVENT_SUM_TENTACULOS_1);
					me->DespawnOrUnsummon(5000);
					DespawnCreatures(53891);
					me->DespawnOrUnsummon(5000);
					me->SummonCreature(140003, -13855.12f, -13614.34f, 270.02f, 4.73f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
					if(Unit* killer = me->FindNearestPlayer(1000.0f))
						killer->SummonGameObject(RAID_MODE(GO_ESPINAZO_LOOT_10N, GO_ESPINAZO_LOOT_25N, GO_ESPINAZO_LOOT_10H, GO_ESPINAZO_LOOT_25H), -12133.66f,  12076.17f, 2.30f, 3.57793f, 0.0f, 0.0f, -0.976295f, 0.216442f, 320000);
*/
				}
      };
};

class npc_tentaculo : public CreatureScript
{
    public:
        npc_tentaculo() : CreatureScript("npc_tentaculo") { }

                CreatureAI* GetAI(Creature* creature) const
                {
                    return GetDragonSoulAI<npc_tentaculoAI>(creature);
                }

                struct npc_tentaculoAI : public BossAI
                {
                    npc_tentaculoAI(Creature* creature) : BossAI(creature, BOSS_DEATHWING)
                    {
                        instance = creature->GetInstanceScript();
                    }

                        InstanceScript* instance;
                        EventMap events;
						
                        void Reset()
                        {
                            events.Reset();
                            me->SetInCombatWithZone();
							_Reset();
                        }

                        void EnterCombat(Unit* /*who*/)
                        {
							events.ScheduleEvent(SPELL_AGARRE_IGNEO, urand(20000,40000));
						}
               void UpdateAI(uint32 const diff)
				{
					if (!UpdateVictim())
                    return;
						
                    events.Update(diff);
					DoMeleeAttackIfReady();
					
					if (me->GetHealth() < me->GetMaxHealth() * 0.50 && me->GetHealth() > me->GetMaxHealth() * 0.25)
					{
						me->SetHealth(me->GetMaxHealth() * 0.20f);
						std::list<Player*> TargetList;
						Map::PlayerList const& Players = me->GetMap()->GetPlayers();
						for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
						{	
							if (Player* player = itr->GetSource())
							{
								player->RemoveAura(105490);
							}	
						}	
					}
					
					while (uint32 eventId = events.ExecuteEvent())
					{
						switch (eventId)
						{
							case SPELL_AGARRE_IGNEO:
								if (Player* jugadorcerca = me->FindNearestPlayer(20.0f, true))
								{
									jugadorcerca->AddAura(105490, jugadorcerca);
									events.ScheduleEvent(SPELL_AGARRE_IGNEO, urand(25000,40000));
								}	
							break;	
						}
					}	
                 }

				void JustDied(Unit* /*Killer*/)
				{
					if (!me->FindNearestCreature(53890, 5.0f, true))
					{
						me->SummonCreature(53890, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 4.72f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
					}
					me->DespawnOrUnsummon(5000);
				}
			};	
};

void AddSC_espinaca_alamuerte()
{
    new npc_tendones();
    new npc_tendones_2();
	new npc_tendones_3();
    new npc_tentaculo();
}
