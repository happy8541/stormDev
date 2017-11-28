/* SCRIPTEADO POR BoT 100%
SKYPE: ALEXHINHO99
*/

#include "ScriptPCH.h"
#include "dragon_soul.h"

enum Events
{
	EVENT_FOCUSEF_ANGER = 1,
	EVENT_PSYCHIC_DRAIN,
	EVENT_DISRUPTING_SHADOWS,
	IRAPORALGUIEN,
	SACAR_PELOTA,
	TENTACULOS,
	COMPROBARPELOTA,
};

enum Spells
{
	SPELL_COMBUSTION         = 100249,
	SPELL_FOCUSED_ANGER      = 104543,
	SPELL_PSYCHIC_DRAIN      = 104322,
	SPELL_DISRUPTING_SHADOWS = 103434,
};

class boss_warlord : public CreatureScript
{
public:
    boss_warlord() : CreatureScript("boss_warlord") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetDragonSoulAI<boss_warlordAI>(creature);
    }

    struct boss_warlordAI: public BossAI
    {
        boss_warlordAI(Creature* creature) : BossAI(creature, BOSS_WARLORD)
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
            events.Reset();

            instance->SetBossState(DATA_PORTALS_ON_OFF, DONE);
            me->RemoveAura(EVENT_FOCUSEF_ANGER);
			DespawnCreatures(55334);
			DespawnCreatures(57875);
            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_FOCUSEF_ANGER, urand(15000,30000));
            events.ScheduleEvent(EVENT_PSYCHIC_DRAIN, urand(20000,40000));
            events.ScheduleEvent(EVENT_DISRUPTING_SHADOWS, urand(25000,25000));
			//Summonear pelota
			me->SummonCreature(55334, -1785.58, -1976.32, -223, 4.27, TEMPSUMMON_CORPSE_DESPAWN, 100000);
            instance->SetBossState(BOSS_WARLORD, IN_PROGRESS);
            instance->SetBossState(DATA_PORTALS_ON_OFF, IN_PROGRESS);
            _EnterCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

			if(!me->FindNearestCreature(57875, 100.0f, true) && !me->FindNearestCreature(55334, 100.0f, true))
			{
				events.ScheduleEvent(TENTACULOS, urand(5000,5000));
			}
			
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FOCUSEF_ANGER:	            
					if(me->FindNearestCreature(55334, 1000.0f, true))
					{
						DoCast(me, SPELL_FOCUSED_ANGER);
					}
					events.ScheduleEvent(EVENT_FOCUSEF_ANGER, urand(60000,60000));
                    break;

                case EVENT_PSYCHIC_DRAIN:
		            DoCastVictim(SPELL_PSYCHIC_DRAIN);
                    events.ScheduleEvent(EVENT_PSYCHIC_DRAIN, urand(60000,120000));
                    break;

                case EVENT_DISRUPTING_SHADOWS:
					if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                       DoCast(target, SPELL_DISRUPTING_SHADOWS);
                    events.ScheduleEvent(EVENT_DISRUPTING_SHADOWS, urand(30000,60000));
                    break;
				case TENTACULOS:
					if(me->FindNearestCreature(38667, 100.0f, true))	
					{					
						DespawnCreatures(57875);
						me->SummonCreature(57875, -1791.67f, -1990.35f, -221.22f, 1.29f, TEMPSUMMON_CORPSE_DESPAWN, 100000);
						me->SummonCreature(57875, -1734.21f, -1985.315, -221.31f, 1.9f, TEMPSUMMON_CORPSE_DESPAWN, 100000);
						me->SummonCreature(57875, -1697.16f, -1940.86f, -221.39f, 2.94f, TEMPSUMMON_CORPSE_DESPAWN, 100000);
						me->SummonCreature(57875, -1700.75f, -1882.29f, -221.29f, 3.5f, TEMPSUMMON_CORPSE_DESPAWN, 100000);
						me->SummonCreature(57875, -1745.10f, -1845.08f, -221.25f, 4.41f, TEMPSUMMON_CORPSE_DESPAWN, 100000);
						me->SummonCreature(57875, -1803.18f, -1849.96f, -221.27, 5.195f, TEMPSUMMON_CORPSE_DESPAWN, 100000);
						me->SummonCreature(57875, -1841.28f, -1894.34f, -221.23, 5.94f, TEMPSUMMON_CORPSE_DESPAWN, 100000);
						me->SummonCreature(57875, -1835.82f, -1952.16f, -221.27f, 5.39f, TEMPSUMMON_CORPSE_DESPAWN, 100000);
						
						std::list<Player*> TargetList;
						Map::PlayerList const& Players = me->GetMap()->GetPlayers();
						for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
						{	
							if (Player* player = itr->GetSource())
							{
								me->AddAura(104378, player);
							}	
						}
						events.ScheduleEvent(SACAR_PELOTA, urand(60000, 60000));
						DespawnCreatures(38667);
						
					}	
					break;
					case SACAR_PELOTA:
						me->SummonCreature(55334, -1785.58, -1976.32, -223, 4.27, TEMPSUMMON_CORPSE_DESPAWN, 100000);
					break;
                default:
                    break;
                }
            }		

            DoMeleeAttackIfReady();
        }

        void JustReachedHome()
        {
            _JustReachedHome();
            instance->SetBossState(BOSS_WARLORD, FAIL);
        }

        void JustDied(Unit* /*killer*/)
        {		
			DespawnCreatures(57875);
			DespawnCreatures(55334);
            instance->SetBossState(BOSS_WARLORD, DONE);
            instance->SetBossState(DATA_PORTALS_ON_OFF, DONE);
        }
    };
};

class npc_pelota : public CreatureScript
{
public:
    npc_pelota() : CreatureScript("npc_pelota") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetDragonSoulAI<npc_pelotaAI>(creature);
    }

    struct npc_pelotaAI: public BossAI
    {
        npc_pelotaAI(Creature* creature) : BossAI(creature, BOSS_WARLORD)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void Reset()
        {
            events.Reset();
            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(IRAPORALGUIEN, urand(1000,1000));
			events.ScheduleEvent(COMPROBARPELOTA, urand(500,500));
            _EnterCombat();
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
		
        void DamageTaken(Unit* /*who*/, uint32& damage)
        {	
        }
		
        Player* SelectRandomPlayer(float range = 0.0f, bool checkLoS = true)
        {
            Map* map = me->GetMap();
            if (!map->IsDungeon())
                return NULL;
        
            Map::PlayerList const &PlayerList = map->GetPlayers();
            if (PlayerList.isEmpty())
                return NULL;
        
            std::list<Player*> temp;
            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                if ((me->IsWithinLOSInMap(i->GetSource()) || !checkLoS) && me->GetVictim() != i->GetSource() &&
                    me->IsWithinDistInMap(i->GetSource(), range) && i->GetSource()->IsAlive())
                    temp.push_back(i->GetSource());
        
            if (!temp.empty())
            {
                std::list<Player*>::const_iterator j = temp.begin();
                advance(j, rand()%temp.size());
                return (*j);
            }
            return NULL;
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
                case IRAPORALGUIEN:
					if (Unit* player = SelectRandomPlayer(100.0f))
						me->GetMotionMaster()->MovePoint(0, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
                    break;
				case COMPROBARPELOTA:
					//al rebotar con un jugador
					if (Unit* pelotero = me->FindNearestPlayer(1.0f, true))
					{
						DoCast(pelotero, SPELL_COMBUSTION);	
						//quitar daño a jugadores cercanos
						DoCast(me, 103527);
						//Aumentar daño recibido en un 5% por cada rebote a zonozz
						if (Creature* u = me->FindNearestCreature(55308, 1000.0f, true))
							me->AddAura(104031, u);
						//Borrar el aura de fuego de la spell combustion
						pelotero->RemoveAura(100249);
						events.ScheduleEvent(IRAPORALGUIEN, urand(3000,3000));
					}
					
					//al chocar con zonozz
					if (Creature* u = me->FindNearestCreature(55308, 0.01f, true))
					{
						DespawnCreatures(55334);
						u->RemoveAura(109410);
						u->RemoveAura(109411);
						u->RemoveAura(109409);
						u->RemoveAura(109543);
						me->SummonCreature(38667, -1791.67f, -1990.35f, -221.22f, 1.29f, TEMPSUMMON_CORPSE_DESPAWN, 100000);
					}
					
					events.ScheduleEvent(COMPROBARPELOTA, urand(500,500));
					break;
                default:
                    break;
                }
            }		

            DoMeleeAttackIfReady();
        }

        void JustReachedHome()
        {
        }

        void JustDied(Unit* /*killer*/)
        {
        }
    };
};

void AddSC_boss_warlord()
{
    new boss_warlord();
	new npc_pelota();
}