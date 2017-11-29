/* ScriptData
Script al 90%
Creado totalmente por BoT para BoTWoW.

yser en la primera
alextstraza en la segunda
nozdormu la 3º
kalecgos en la 4º
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

#define TRALL_MENU "Estamos preparados!"
#define TELE_MENU_1 "1st Area"
#define TELE_MENU_2 "2nd Area"
#define TELE_MENU_3 "3rd Area"
#define TELE_MENU_4 "4th Area"

enum Events
{
	// Deathwing
	EVENT_ASSAULT_ASPECTS = 1,
	EVENT_CATACLYSM,
	EVENT_CORRUPTING_PARASITE,
	EVENT_ELEMENTIUM_BOLT,
	EVENT_SUMMONEAR_FH,
	MATAR_ALAMUERTE,
	EVENT_SANGRE_REGENERATIVA,	

	//tentacle
	EVENT_AGONUZUNG_PAIN,

	//other
	EVENT_SUMMON,
	EVENT_SUMMON_50,
	EVENT_SUMMON_25,
	EVENT_SUMMON_1,
	ATTACK_START,

	//Phase
	PHASE_1,
	PHASE_2,
	HAS_20PROCENT_HEALTH_NEW_PHASE,

	//Phase 2
	EVENT_ELEMENTIUM_FRAGMENT,
	EVENT_ELEMENTIUM_TERROR,
	EVENT_CORRUPTED_BLOOD,
	EVENT_CONGEALING_BLOOD,

	//Phase 2 mob events
	EVENT_SHRAPNEL,
	EVENT_TETANUS,
	EVENT_CONGEALING_BLOOD_CAST,

	//trall
	EVENT_SAY_TRALL_START,
	EVENT_SAY_TRALL_1,
};

enum Spells
{
	//DeathWing
    SPELL_ASSAULT_ASPECTS     = 107018,
    SPELL_CATACLYSM           = 106523,
    SPELL_CORRUPTING_PARASITE = 108649,
    SPELL_ELEMENTIUM_BOLT     = 105651,

	// Mutated corruption
    SPELL_IMPALE              = 106400,
    SPELL_IMPALE_ASPECT       = 107029,
	
	// tentacle
    SPELL_BURNING_BLODD       = 105401,
    SPELL_AGONUZUNG_PAIN      = 106548,
    SPELL_CRUSH               = 106385,

	// Phase 2
    SPELL_CONGEALING_BLOOD    = 109102,
    SPELL_SHRAPNEL            = 106791,
    SPELL_TETANUS             = 106728,
    SPELL_CORRUPTED_BLOOD     = 106835,
};

enum Texts
{
	//trall
    SAY_TRALL_START           = 0,
    SAY_TRALL_START_1         = 1,
    SAY_TRALL_20PROCENT       = 2,
    SAY_TRALL_DEATH_DEATHWING = 3,

	//Deathwing
    SAY_AGGRO    = 0,
    SAY_KILL_ALL = 1,
    SAY_SPELL_1  = 2,
    SAY_SPELL_2  = 3,
    SAY_SPELL_3  = 4,
};

class boss_deathwing : public CreatureScript
{
public:
    boss_deathwing() : CreatureScript("boss_deathwing") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetDragonSoulAI<boss_deathwingAI>(creature);
    }

    struct boss_deathwingAI: public BossAI
    {
        boss_deathwingAI(Creature* creature) : BossAI(creature, BOSS_DEATHWING)
        {
            instance = creature->GetInstanceScript();
        }

		InstanceScript* instance;
        EventMap events;

		void Reset()
		{
			events.Reset();
			me->RemoveAllAuras();
			instance->SetBossState(DATA_PORTALS_ON_OFF, DONE);
			me->SetCanFly(true);
			me->SetReactState(REACT_AGGRESSIVE);		
			me->SetInCombatWithZone();		

			Talk(SAY_AGGRO);
			_Reset();
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
		
		void EnterEvadeMode()
		{
			Reset();			
			DespawnCreatures(56173);
			DespawnCreatures(57694);
			DespawnCreatures(57686);
			DespawnCreatures(57696);
			DespawnCreatures(57695);
			DespawnCreatures(56844);
			DespawnCreatures(56846);
			DespawnCreatures(56167);
			DespawnCreatures(56168);
			DespawnCreatures(56168);
			//dragones
			std::list<Player*> TargetList;
			Map::PlayerList const& Players = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
			{	
				if (Player* player = itr->GetSource())
				{
					//BORRAR AURA DRAGONES
					player->RemoveAura(105825);
					player->RemoveAura(106027);
					player->RemoveAura(106026);
					player->RemoveAura(106456);
				}
			}				
			DespawnCreatures(56100);
			DespawnCreatures(56099);
			DespawnCreatures(56102);
			DespawnCreatures(56101);
			me->SummonCreature(56103, -12140.29f, 12602.50f, 2.30f, 1.058f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
			if(Creature* trallresp = me->FindNearestCreature(56103, 100.0f, true))
			{
				trallresp->SetDeathState(ALIVE);
				trallresp->Respawn();
			}
			if(Creature* creature = me->FindNearestCreature(56103, 100.0f))
				creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
			Talk(SAY_KILL_ALL);
			_EnterEvadeMode();
		}

		void EnterCombat(Unit* /*who*/)
		{
			instance->SetBossState(DATA_PORTALS_ON_OFF, IN_PROGRESS);
			events.ScheduleEvent(PHASE_1, 1);

			if(instance)
				instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
			events.ScheduleEvent(EVENT_SAY_TRALL_START, 5000);
			_EnterCombat();
		}

		void UpdateAI(const uint32 diff)
		{
			if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
				 return;

			events.Update(diff);
			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				// SAY
				case EVENT_SAY_TRALL_START:
					if(Creature* trall = me->FindNearestCreature(NPC_MAELSTROM_TRALL, 300.0f, true))
					    trall->AI()->Talk(SAY_TRALL_START);
					events.ScheduleEvent(EVENT_SAY_TRALL_1, 3000);
					break;

				case EVENT_SAY_TRALL_1:
					if(Creature* trall = me->FindNearestCreature(NPC_MAELSTROM_TRALL, 300.0f, true))
					    trall->AI()->Talk(SAY_TRALL_START_1);
					break;

			    //Phase 1
				case PHASE_1:
					events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, urand(60000,100000));
					if(IsHeroic()) // no work
					    events.ScheduleEvent(EVENT_CATACLYSM, 900000); // no work
					events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, urand(10000,30000));
					events.ScheduleEvent(EVENT_ELEMENTIUM_BOLT, 150); //no work
					events.ScheduleEvent(EVENT_SANGRE_REGENERATIVA, urand(10000,20000));
					events.ScheduleEvent(HAS_20PROCENT_HEALTH_NEW_PHASE, 150);
					break;

				case HAS_20PROCENT_HEALTH_NEW_PHASE:
					if(me->GetHealthPct() < 22)
					{
						events.CancelEvent(HAS_20PROCENT_HEALTH_NEW_PHASE);
						events.ScheduleEvent(PHASE_2, 1000);
						if(Creature* trall = me->FindNearestCreature(NPC_MAELSTROM_TRALL, 300.0f, true))
						{
					        trall->AI()->Talk(SAY_TRALL_20PROCENT);
							if(Player* players = trall->FindNearestPlayer(500.0f))
							    trall->SendPlaySound(26600, players);
						}
						
					}
					events.ScheduleEvent(HAS_20PROCENT_HEALTH_NEW_PHASE, 5000);
					break;

				case EVENT_ASSAULT_ASPECTS:
					if(Unit* target = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_MAELSTROM_TRALL)))
						DoCast(target, SPELL_ASSAULT_ASPECTS);
					events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, urand(40000,80000));
					break;
					
				case EVENT_SANGRE_REGENERATIVA:
					if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
					{
						DoCast(target, 105863);
					}
					events.ScheduleEvent(EVENT_SANGRE_REGENERATIVA, urand(8000,12000));
					break;				
					
				case EVENT_CORRUPTING_PARASITE:
					if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
					{
						DoCast(target, SPELL_CORRUPTING_PARASITE);
						me->SummonCreature(NPC_CORRUPTION_PARASITE, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
					}
					events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, urand(25000,40000));
					break;

				case PHASE_2:
					DespawnCreatures(57479);
					DespawnCreatures(56263);
					events.CancelEvent(EVENT_ASSAULT_ASPECTS);
					events.CancelEvent(EVENT_CATACLYSM); // no work
					events.CancelEvent(EVENT_CORRUPTING_PARASITE);
					events.CancelEvent(EVENT_ELEMENTIUM_BOLT); // no work
					events.CancelEvent(PHASE_2);
					events.CancelEvent(HAS_20PROCENT_HEALTH_NEW_PHASE);
					events.ScheduleEvent(EVENT_SUMMONEAR_FH, urand(1000,1000));	
					events.ScheduleEvent(MATAR_ALAMUERTE, 1000);					
					if(IsHeroic())
					events.ScheduleEvent(EVENT_CONGEALING_BLOOD, urand(15000,30000));
					events.ScheduleEvent(EVENT_ELEMENTIUM_FRAGMENT, urand(15000,30000));
					events.ScheduleEvent(EVENT_ELEMENTIUM_TERROR, urand(20000,60000));
					events.ScheduleEvent(EVENT_CORRUPTED_BLOOD, 150);
					break;

				case EVENT_CORRUPTED_BLOOD:
					if(me->GetHealthPct() < 15)
					{
						events.CancelEvent(EVENT_CORRUPTED_BLOOD);
						DoCast(SPELL_CORRUPTED_BLOOD);
					}
					events.ScheduleEvent(EVENT_CORRUPTED_BLOOD, 5000);
					break;

				case EVENT_SUMMONEAR_FH:
						me->SummonCreature(49533, -11941.162, 12239.24, 5.36, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
						events.ScheduleEvent(MATAR_ALAMUERTE, 150);
					break;
				case MATAR_ALAMUERTE:
						if(!me->FindNearestCreature(49533, 1000.0f))
							me->Kill(me);	
						events.ScheduleEvent(MATAR_ALAMUERTE, 1000);	
					break;					
					
				case EVENT_CONGEALING_BLOOD:
					if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
						me->SummonCreature(NPC_CONGEALING_BLOOD, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
					events.CancelEvent(EVENT_CORRUPTED_BLOOD);
					events.ScheduleEvent(EVENT_CORRUPTED_BLOOD, urand(30000,80000));
					break;

				case EVENT_ELEMENTIUM_TERROR:
					events.CancelEvent(EVENT_ELEMENTIUM_TERROR);
					events.ScheduleEvent(EVENT_ELEMENTIUM_TERROR, urand(60000,90000));
					if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
						me->SummonCreature(NPC_ELEMENTIUM_FRAGMENT, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
					if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
						me->SummonCreature(NPC_ELEMENTIUM_FRAGMENT, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
					if(IsHeroic())
						if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
							me->SummonCreature(NPC_ELEMENTIUM_FRAGMENT, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
					break;

				case EVENT_ELEMENTIUM_FRAGMENT:
					events.CancelEvent(EVENT_ELEMENTIUM_FRAGMENT);
					events.ScheduleEvent(EVENT_ELEMENTIUM_FRAGMENT, urand(30000,40000));
					if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
						me->SummonCreature(NPC_ELEMENTIUM_TERROR, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
					if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
						me->SummonCreature(NPC_ELEMENTIUM_TERROR, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
					if(IsHeroic())	
						if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
							me->SummonCreature(NPC_ELEMENTIUM_TERROR, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}

		void JustDied(Unit* pkiller)
		{
			std::list<Player*> TargetList;
			Map::PlayerList const& Players = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
			{	
				if (Player* player = itr->GetSource())
				{
					if (AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(6177))
					{
						player->CompletedAchievement(achievementEntry);
					}	
					if (AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(6116))
					{
						if(IsHeroic())
							player->CompletedAchievement(achievementEntry);
					}
					//BORRAR AURA DRAGONES
					player->RemoveAura(105825);
					player->RemoveAura(106027);
					player->RemoveAura(106026);
					player->RemoveAura(106456);
				}
			}	
			DespawnCreatures(56100);
			DespawnCreatures(56099);
			DespawnCreatures(56102);
			DespawnCreatures(56101);			
			instance->SetBossState(DATA_PORTALS_ON_OFF, DONE);
			if(instance)
				instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
			if(Creature* creature = me->FindNearestCreature(57694, 100.0f))
				me->Kill(creature);
			if(Creature* creature = me->FindNearestCreature(57686, 100.0f))
				me->Kill(creature);
			if(Creature* creature = me->FindNearestCreature(57696, 100.0f))
				me->Kill(creature);
			if(Creature* creature = me->FindNearestCreature(57695, 100.0f))
				me->Kill(creature);
			if(Creature* creature = me->FindNearestCreature(56844, 100.0f))
				me->Kill(creature);
			if(Unit* killer = me->FindNearestPlayer(1000.0f))
			    killer->SummonGameObject(RAID_MODE(GO_DEATHWING_LOOT_10N, GO_DEATHWING_LOOT_25N, GO_DEATHWING_LOOT_10H, GO_DEATHWING_LOOT_25H), -11961.41f,  12261.17f, 1.29f, 3.57793f, 0.0f, 0.0f, -0.976295f, 0.216442f, 320000);
			if(Creature* trall = me->FindNearestCreature(NPC_MAELSTROM_TRALL, 300.0f, true))
				trall->AI()->Talk(SAY_TRALL_DEATH_DEATHWING);
			me->DespawnOrUnsummon(5000);
            _JustDied();
        }
    };
};

class npc_maelstrom_trall : public CreatureScript
{
    public:
        npc_maelstrom_trall() : CreatureScript("npc_maelstrom_trall") { }

		bool OnGossipHello(Player* player, Creature* creature)
		{
			 if (InstanceScript* instance = creature->GetInstanceScript())
			 {
			     player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, TRALL_MENU, GOSSIP_SENDER_MAIN, 10);
			 }

			 player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			 return true;
		}

		bool OnGossipSelect(Player *player, Creature *creature, uint32 sender, uint32 uiAction)
		{
			if (sender == GOSSIP_SENDER_MAIN)
			{
				player->PlayerTalkClass->ClearMenus();
				switch(uiAction)
				{
				case 10:
					if (InstanceScript* instance = creature->GetInstanceScript())
					{
					    player->CLOSE_GOSSIP_MENU();
						instance->SetData(DATA_ATTACK_DEATHWING, IN_PROGRESS);
						creature->SummonCreature(NPC_DEATHWING_1, -11903.9f, 11989.1f, -113.204f, 2.16421f, TEMPSUMMON_TIMED_DESPAWN, 12000000);
						creature->SummonCreature(57694, -11967.1f, 11958.8f, -49.9822f, 2.16421f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);
						creature->SummonCreature(57686, -11852.1f, 12036.4f, -49.9821f, 2.16421f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);
						creature->SummonCreature(57696, -11913.8f, 11926.5f, -60.3749f, 2.16421f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);
						creature->SummonCreature(57695, -11842.2f, 11974.8f, -60.3748f, 2.16421f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);
						creature->SummonCreature(56844, -11857.0f, 11795.6f, -73.9549f, 2.23402f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);
						creature->SummonCreature(56846, -12066.59f, 12144.79f, -2.65f, 2.7182f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);
						creature->SummonCreature(56167, -12013.59f, 12197.6f, -5.9549f, 2.24402f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);		
						creature->SummonCreature(56168, -12094.76f, 12070.12f, 2.88f, 2.7182f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);
						creature->SummonCreature(56168, -11952.56f, 12255.62f, 1.29f, 1.81f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);
						//dragones
						creature->SummonCreature(56100, -12155.20f, 12089.29f, 2.3f, 5.9f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);
						creature->SummonCreature(56099, -12115.51f, 12170.11f, -2.73f, 5.80f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);
						creature->SummonCreature(56102, -12055.09f, 12252.00f, -6.73f, 5.4f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);
						creature->SummonCreature(56101, -11956.59f, 12295.29f, 1.29f, 5.11f, TEMPSUMMON_CORPSE_DESPAWN, 6000000);
						creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
					}
				    break;
				default:
					break;
				}
			}
			return true;
		}
};

class Teleportation_to_the_platforms : public CreatureScript
{
    public:
        Teleportation_to_the_platforms() : CreatureScript("Teleportation_to_the_platforms") { }

		bool OnGossipHello(Player* player, Creature* creature)
		{
			 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, TELE_MENU_1, GOSSIP_SENDER_MAIN, 20);
			 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, TELE_MENU_2, GOSSIP_SENDER_MAIN, 21);
			 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, TELE_MENU_3, GOSSIP_SENDER_MAIN, 22);
			 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, TELE_MENU_4, GOSSIP_SENDER_MAIN, 23);

			 player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			 return true;
		}

		bool OnGossipSelect(Player *player, Creature *creature, uint32 sender, uint32 uiAction)
		{
			if (sender == GOSSIP_SENDER_MAIN)
			{
				player->PlayerTalkClass->ClearMenus();
				switch(uiAction)
				{
				case 20:
					player->CLOSE_GOSSIP_MENU();
					player->TeleportTo(967, -11961.371f, 12294.102f, 1.284f, 5.094f);
				    break;
				case 21:
					player->CLOSE_GOSSIP_MENU();
					player->TeleportTo(967, -12058.748f, 12245.875f, -6.151f, 5.464f);
				    break;
				case 22:
					player->CLOSE_GOSSIP_MENU();
					player->TeleportTo(967, -12121.12f, 12174.846f, -2.735f, 5.604f);
				    break;
				case 23:
					player->CLOSE_GOSSIP_MENU();
					player->TeleportTo(967, -12157.026f, 12090.791f, 2.308f, 6.029f);
				    break;
				default:
					break;
				}
			}
			return true;
		}
};

class npc_arm_tentacle_one : public CreatureScript
{
    public:
        npc_arm_tentacle_one() : CreatureScript("npc_arm_tentacle_one") { }

		CreatureAI* GetAI(Creature* creature) const
		{
		    return GetDragonSoulAI<npc_arm_tentacle_oneAI>(creature);
		}

		struct npc_arm_tentacle_oneAI : public ScriptedAI
		{
		    npc_arm_tentacle_oneAI(Creature* creature) : ScriptedAI(creature)
		    {
			    instance = creature->GetInstanceScript();
		    }

			InstanceScript* instance;
			EventMap events;

			void Reset()
			{
				me->RemoveAllAuras();
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
				me->SetCanFly(true);
				events.Reset();
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
			
			void EnterCombat(Unit* /*who*/)
			{
				DoCast(SPELL_BURNING_BLODD);
				events.ScheduleEvent(EVENT_SUMMON, 30000);
				events.ScheduleEvent(EVENT_SUMMON_50, 30000);
				events.ScheduleEvent(EVENT_SUMMON_25, 30000);
				instance->SetData(DATA_DAMAGE_DEATHWING, IN_PROGRESS);
			}

			void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);			
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                while (uint32 eventId = events.ExecuteEvent())
				{
                    switch (eventId)
                    {
							case EVENT_SUMMON:
							events.ScheduleEvent(EVENT_SUMMON, 5000);
							if(me->GetHealthPct() < 75)
							{
								events.CancelEvent(EVENT_SUMMON);
								if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
								me->SummonCreature(NPC_MYTATED_CORRUPTION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							break;
							case EVENT_SUMMON_50:
							events.ScheduleEvent(EVENT_SUMMON_50, 5000);
							if(me->GetHealthPct() < 50)
							{
								events.CancelEvent(EVENT_SUMMON_50);
								if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
								me->SummonCreature(NPC_MYTATED_CORRUPTION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							break;		
						case EVENT_SUMMON_25:
							events.ScheduleEvent(EVENT_SUMMON_25, 5000);
							if(me->GetHealthPct() < 25)
							{
								events.CancelEvent(EVENT_SUMMON_25);
								if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
								me->SummonCreature(NPC_MYTATED_CORRUPTION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							break;
					}
				}
			}

			void JustDied(Unit* /*killer*/)
            {				
				if(Creature* creature = me->FindNearestCreature(56173, 1000.0f))
				{	
					creature->SetHealth(creature->GetHealth() * 0.8f);
				}
				DespawnCreatures(57479);
				DespawnCreatures(56263);				
				instance->SetData(DATA_DAMAGE_DEATHWING, DONE);
			}

		};
};

class npc_arm_tentacle_two : public CreatureScript
{
    public:
        npc_arm_tentacle_two() : CreatureScript("npc_arm_tentacle_two") { }

		CreatureAI* GetAI(Creature* creature) const
		{
		    return GetDragonSoulAI<npc_arm_tentacle_twoAI>(creature);
		}

		struct npc_arm_tentacle_twoAI : public ScriptedAI
		{
		    npc_arm_tentacle_twoAI(Creature* creature) : ScriptedAI(creature)
		    {
			    instance = creature->GetInstanceScript();
		    }

			InstanceScript* instance;
			EventMap events;

			void Reset()
			{
				me->RemoveAllAuras();
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
				me->SetCanFly(true);
				events.Reset();
			}

			void EnterCombat(Unit* /*who*/)
			{
				DoCast(SPELL_BURNING_BLODD);
				events.ScheduleEvent(EVENT_SUMMON, 30000);
				events.ScheduleEvent(EVENT_SUMMON_50, 30000);
				events.ScheduleEvent(EVENT_SUMMON_25, 30000);
				instance->SetData(DATA_DAMAGE_DEATHWING, IN_PROGRESS);
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
			
			void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                while (uint32 eventId = events.ExecuteEvent())
				{
                    switch (eventId)
                    {
							case EVENT_SUMMON:
							events.ScheduleEvent(EVENT_SUMMON, 5000);
							if(me->GetHealthPct() < 75)
							{
								events.CancelEvent(EVENT_SUMMON);
								if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
								me->SummonCreature(NPC_MYTATED_CORRUPTION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							break;
							case EVENT_SUMMON_50:
							events.ScheduleEvent(EVENT_SUMMON_50, 5000);
							if(me->GetHealthPct() < 50)
							{
								events.CancelEvent(EVENT_SUMMON_50);
								if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
								me->SummonCreature(NPC_MYTATED_CORRUPTION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							break;		
						case EVENT_SUMMON_25:
							events.ScheduleEvent(EVENT_SUMMON_25, 5000);
							if(me->GetHealthPct() < 25)
							{
								events.CancelEvent(EVENT_SUMMON_25);
								if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
								me->SummonCreature(NPC_MYTATED_CORRUPTION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							break;
					}
				}
			}

			void JustDied(Unit* /*killer*/)
            {
				if(Creature* creature = me->FindNearestCreature(56173, 1000.0f))
				{	
					creature->SetHealth(creature->GetHealth() * 0.7f);
				}	
				DespawnCreatures(57479);
				DespawnCreatures(56263);
				instance->SetData(DATA_DAMAGE_DEATHWING, DONE);
			}

		};
};

class npc_wing_tentacle_one : public CreatureScript
{
    public:
        npc_wing_tentacle_one() : CreatureScript("npc_wing_tentacle_one") { }

		CreatureAI* GetAI(Creature* creature) const
		{
		    return GetDragonSoulAI<npc_wing_tentacle_oneAI>(creature);
		}

		struct npc_wing_tentacle_oneAI : public ScriptedAI
		{
		    npc_wing_tentacle_oneAI(Creature* creature) : ScriptedAI(creature)
		    {
			    instance = creature->GetInstanceScript();
		    }

			InstanceScript* instance;
			EventMap events;
			
			void DespawnCreatures(uint32 entry)
			{
				std::list<Creature*> creatures;
				GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);
			
				if (creatures.empty())
				return;
			
				for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
					(*iter)->DespawnOrUnsummon();
			}
			
			void Reset()
			{
				me->RemoveAllAuras();
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
				me->SetCanFly(true);
				events.Reset();
			}

			void EnterCombat(Unit* /*who*/)
			{
				DoCast(SPELL_BURNING_BLODD);
				events.ScheduleEvent(EVENT_SUMMON, 30000);
				events.ScheduleEvent(EVENT_SUMMON_50, 30000);
				events.ScheduleEvent(EVENT_SUMMON_25, 30000);;
				instance->SetData(DATA_DAMAGE_DEATHWING, IN_PROGRESS);
			}

			void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                while (uint32 eventId = events.ExecuteEvent())
				{
                    switch (eventId)
                    {
							case EVENT_SUMMON:
							events.ScheduleEvent(EVENT_SUMMON, 5000);
							if(me->GetHealthPct() < 75)
							{
								events.CancelEvent(EVENT_SUMMON);
								if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
								me->SummonCreature(NPC_MYTATED_CORRUPTION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							break;
							case EVENT_SUMMON_50:
							events.ScheduleEvent(EVENT_SUMMON_50, 5000);
							if(me->GetHealthPct() < 50)
							{
								events.CancelEvent(EVENT_SUMMON_50);
								if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
								me->SummonCreature(NPC_MYTATED_CORRUPTION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							break;		
						case EVENT_SUMMON_25:
							events.ScheduleEvent(EVENT_SUMMON_25, 5000);
							if(me->GetHealthPct() < 25)
							{
								events.CancelEvent(EVENT_SUMMON_25);
								if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
								me->SummonCreature(NPC_MYTATED_CORRUPTION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							break;						
					}	
				}
			}

			void JustDied(Unit* killer)
            {
				if(Creature* creature = me->FindNearestCreature(56173, 1000.0f))
				{	
					creature->SetHealth(creature->GetHealth() * 0.6f);
				}	
				DespawnCreatures(57479);
				DespawnCreatures(56263);				
				instance->SetData(DATA_DAMAGE_DEATHWING, DONE);
			}

		};
};

class npc_wing_tentacle_two : public CreatureScript
{
    public:
        npc_wing_tentacle_two() : CreatureScript("npc_wing_tentacle_two") { }

		CreatureAI* GetAI(Creature* creature) const
		{
		    return GetDragonSoulAI<npc_wing_tentacle_twoAI>(creature);
		}

		struct npc_wing_tentacle_twoAI : public ScriptedAI
		{
		    npc_wing_tentacle_twoAI(Creature* creature) : ScriptedAI(creature)
		    {
			    instance = creature->GetInstanceScript();
		    }

			InstanceScript* instance;
			EventMap events;

			void Reset()
			{
				me->RemoveAllAuras();
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
				me->SetCanFly(true);
				events.Reset();
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
			
			void EnterCombat(Unit* /*who*/)
			{
				DoCast(SPELL_BURNING_BLODD);
				events.ScheduleEvent(EVENT_SUMMON, 30000);
				events.ScheduleEvent(EVENT_SUMMON_50, 30000);
				events.ScheduleEvent(EVENT_SUMMON_25, 30000);
				instance->SetData(DATA_DAMAGE_DEATHWING, IN_PROGRESS);
			}

			void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                while (uint32 eventId = events.ExecuteEvent())
				{
                    switch (eventId)
                    {
							case EVENT_SUMMON:
							events.ScheduleEvent(EVENT_SUMMON, 5000);
							if(me->GetHealthPct() < 75)
							{
								events.CancelEvent(EVENT_SUMMON);
								if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
								me->SummonCreature(NPC_MYTATED_CORRUPTION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							break;
							case EVENT_SUMMON_50:
							events.ScheduleEvent(EVENT_SUMMON_50, 5000);
							if(me->GetHealthPct() < 50)
							{
								events.CancelEvent(EVENT_SUMMON_50);
								if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
								me->SummonCreature(NPC_MYTATED_CORRUPTION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							break;		
						case EVENT_SUMMON_25:
							events.ScheduleEvent(EVENT_SUMMON_25, 5000);
							if(me->GetHealthPct() < 25)
							{
								events.CancelEvent(EVENT_SUMMON_25);
								if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
								me->SummonCreature(NPC_MYTATED_CORRUPTION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 120000);
							}
							break;		
					}			
				}
			}

			void JustDied(Unit* killer)
            {
				if(Creature* creature = me->FindNearestCreature(56173, 1000.0f))
				{	
					creature->SetHealth(creature->GetHealth() * 0.5f);
				}	
				DespawnCreatures(57479);
				DespawnCreatures(56263);				
				instance->SetData(DATA_DAMAGE_DEATHWING, DONE);
			}
		};
};

// aspectos

class npc_ysera_dw : public CreatureScript
{
    public:
        npc_ysera_dw() : CreatureScript("npc_ysera_dw") { }

		CreatureAI* GetAI(Creature* creature) const
		{
		    return GetDragonSoulAI<npc_ysera_dwAI>(creature);
		}

		struct npc_ysera_dwAI : public ScriptedAI
		{
		    npc_ysera_dwAI(Creature* creature) : ScriptedAI(creature)
		    {
			    instance = creature->GetInstanceScript();
		    }

			InstanceScript* instance;
			EventMap events;

			void Reset()
			{
				me->RemoveAllAuras();
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
				me->SetReactState(REACT_PASSIVE);
				me->SetCanFly(true);
				events.Reset();
			}

			void EnterCombat(Unit* /*who*/)
			{
			}

			void UpdateAI(const uint32 diff)
            {
                events.Update(diff);
				std::list<Player*> TargetList;
				Map::PlayerList const& Players = me->GetMap()->GetPlayers();
				for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
				{	
					if (Player* player = itr->GetSource())
					{
						if(!player->HasAura(106456) && me->IsInRange(player, 0.0f, 50.0f, true))
						{
							player->RemoveAura(105825);
							player->RemoveAura(106027);
							player->RemoveAura(106026);
							player->AddAura(106456, player);
						}	
					}	
				}				
			}

			void JustDied(Unit* killer)
            {
			}

		};
};

class npc_alextstraza_dw : public CreatureScript
{
    public:
        npc_alextstraza_dw() : CreatureScript("npc_alextstraza_dw") { }

		CreatureAI* GetAI(Creature* creature) const
		{
		    return GetDragonSoulAI<npc_alextstraza_dwAI>(creature);
		}

		struct npc_alextstraza_dwAI : public ScriptedAI
		{
		    npc_alextstraza_dwAI(Creature* creature) : ScriptedAI(creature)
		    {
			    instance = creature->GetInstanceScript();
		    }

			InstanceScript* instance;
			EventMap events;

			void Reset()
			{
				me->RemoveAllAuras();
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
				me->SetReactState(REACT_PASSIVE);
				me->SetCanFly(true);
				events.Reset();
			}

			void EnterCombat(Unit* /*who*/)
			{
			}

			void UpdateAI(const uint32 diff)
            {
                events.Update(diff);
				std::list<Player*> TargetList;
				Map::PlayerList const& Players = me->GetMap()->GetPlayers();
				for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
				{	
					if (Player* player = itr->GetSource())
					{
						if(!player->HasAura(105825) && me->IsInRange(player, 0.0f, 50.0f, true))
						{
							player->RemoveAura(106027);
							player->RemoveAura(106026);
							player->RemoveAura(106456);
							player->AddAura(105825, player);
						}	
					}	
				}				
			}

			void JustDied(Unit* killer)
            {
			}

		};
};

class npc_nozdormu_dw : public CreatureScript
{
    public:
        npc_nozdormu_dw() : CreatureScript("npc_nozdormu_dw") { }

		CreatureAI* GetAI(Creature* creature) const
		{
		    return GetDragonSoulAI<npc_nozdormu_dwAI>(creature);
		}

		struct npc_nozdormu_dwAI : public ScriptedAI
		{
		    npc_nozdormu_dwAI(Creature* creature) : ScriptedAI(creature)
		    {
			    instance = creature->GetInstanceScript();
		    }

			InstanceScript* instance;
			EventMap events;

			void Reset()
			{
				me->RemoveAllAuras();
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
				me->SetCanFly(true);
				events.Reset();
			}

			void EnterCombat(Unit* /*who*/)
			{
			}

			void UpdateAI(const uint32 diff)
            {
                events.Update(diff);
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
				me->SetReactState(REACT_PASSIVE);
				std::list<Player*> TargetList;
				Map::PlayerList const& Players = me->GetMap()->GetPlayers();
				for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
				{	
					if (Player* player = itr->GetSource())
					{
						if(!player->HasAura(106027) && me->IsInRange(player, 0.0f, 50.0f, true))
						{
							player->RemoveAura(105825);
							player->RemoveAura(106026);
							player->RemoveAura(106456);
							player->AddAura(106027, player);
						}	
					}	
				}				
			}

			void JustDied(Unit* killer)
            {
			}

		};
};

class npc_kalecgos_dw : public CreatureScript
{
    public:
        npc_kalecgos_dw() : CreatureScript("npc_kalecgos_dw") { }

		CreatureAI* GetAI(Creature* creature) const
		{
		    return GetDragonSoulAI<npc_kalecgos_dwAI>(creature);
		}

		struct npc_kalecgos_dwAI : public ScriptedAI
		{
		    npc_kalecgos_dwAI(Creature* creature) : ScriptedAI(creature)
		    {
			    instance = creature->GetInstanceScript();
		    }

			InstanceScript* instance;
			EventMap events;

			void Reset()
			{
				me->RemoveAllAuras();
				me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
				me->SetReactState(REACT_PASSIVE);
				me->SetCanFly(true);
				events.Reset();
			}

			void EnterCombat(Unit* /*who*/)
			{
			}

			void UpdateAI(const uint32 diff)
            {
				events.Update(diff);
				std::list<Player*> TargetList;
				Map::PlayerList const& Players = me->GetMap()->GetPlayers();
				for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
				{	
					if (Player* player = itr->GetSource())
					{
						if(!player->HasAura(106026) && me->IsInRange(player, 0.0f, 50.0f, true))
						{
							player->RemoveAura(105825);
							player->RemoveAura(106027);
							player->RemoveAura(106456);
							player->AddAura(106026, player);
						}	
					}	
				}				
			}

			void JustDied(Unit* killer)
            {
			}

		};
};

void AddSC_boss_deathwing()
{
    new boss_deathwing();
    new npc_maelstrom_trall();
    new npc_arm_tentacle_one();
    new npc_arm_tentacle_two();
    new npc_wing_tentacle_one();
	new npc_wing_tentacle_two();
	new npc_ysera_dw();
	new npc_alextstraza_dw();
	new npc_nozdormu_dw();
	new npc_kalecgos_dw();
	new Teleportation_to_the_platforms();
    //new npc_mytated_corruption();
    //new npc_maelstrom_alexstrasza();
    //new npc_maelstrom_kalecgos();
    //new npc_maelstrom_ysera();
    //new npc_maelstrom_nozdormy();
}
