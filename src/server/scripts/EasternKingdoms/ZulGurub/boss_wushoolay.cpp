#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulgurub.h"

enum Yells
{
    SAY_AGGRO                      = 0,
    SAY_KILL_PLAYER_1              = 1,
    SAY_KILL_PLAYER_2              = 2,
    SAY_LIGHT_RUSH_1               = 3,
    SAY_LIGHT_RUSH_2               = 4,
    SAY_LIGHT_RUSH_3               = 5,
    SAY_LIGHT_NUKE_1               = 6,
    SAY_LIGHT_NUKE_2               = 7,
    SAY_DEATH                      = 8
};

enum Spells
{
    SPELL_FORKED_LIGHTNING         = 96712,
    SPELL_LIGHTNING_CLOUD          = 96710,
    SPELL_LIGHTNING_ROD            = 96698,
    SPELL_LIGHTNING_RUSH           = 96697,
    SPELL_STORM_CHARGE             = 107981
};

enum Events
{
    EVENT_FORKED_LIGHTNING         = 1,
    EVENT_LIGHTNING_CLOUD,
    EVENT_LIGHTNING_ROD,
    EVENT_LIGHTNING_RUSH,
    EVENT_LIGHTNING_RUSH_CHARGE,
};

class boss_wushoolay : public CreatureScript
{
    public:
        boss_wushoolay() : CreatureScript("boss_wushoolay") { }

        struct boss_wushoolayAI : public BossAI
        {
            boss_wushoolayAI(Creature* creature) : BossAI(creature, DATA_WUSHOOLAY) { }

            void Reset()
            {
                _Reset();
                if (GameObject* forcefield = me->FindNearestGameObject(GO_THE_CACHE_OF_MADNESS_DOOR, 150.0f))
                    me->RemoveGameObject(forcefield, true);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                me->SummonGameObject(GO_THE_CACHE_OF_MADNESS_DOOR, -11938.6f, -1843.32f, 61.7272f, 0.0899053f, 0, 0, 0, 0, 0);
                events.ScheduleEvent(EVENT_FORKED_LIGHTNING, 5000);
                events.ScheduleEvent(EVENT_LIGHTNING_CLOUD, 15000);
                events.ScheduleEvent(EVENT_LIGHTNING_RUSH, 14000);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
                if (GameObject* forcefield = me->FindNearestGameObject(GO_THE_CACHE_OF_MADNESS_DOOR, 150.0f))
                    me->RemoveGameObject(forcefield, true);
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(RAND(SAY_KILL_PLAYER_1, SAY_KILL_PLAYER_2));
            }

            void UpdateAI(uint32 const diff)
            {
                if(!UpdateVictim())
                    return;

                events.Update(diff);

                if(me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_FORKED_LIGHTNING:
                            DoCastVictim(SPELL_FORKED_LIGHTNING);
                            events.ScheduleEvent(EVENT_FORKED_LIGHTNING, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            break;
                        case EVENT_LIGHTNING_CLOUD:
                            DoCast(me, SPELL_LIGHTNING_CLOUD);
                            events.ScheduleEvent(EVENT_LIGHTNING_CLOUD, urand(20*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            break;
                        case EVENT_LIGHTNING_RUSH:
                        {
                            Talk(RAND(SAY_LIGHT_RUSH_1, SAY_LIGHT_RUSH_2, SAY_LIGHT_RUSH_3));
                            DoCast(me, SPELL_LIGHTNING_RUSH);
                            events.ScheduleEvent(EVENT_LIGHTNING_ROD, 3500);
                            events.ScheduleEvent(EVENT_LIGHTNING_RUSH_CHARGE, 2700);
                            events.ScheduleEvent(EVENT_LIGHTNING_RUSH, 20*IN_MILLISECONDS);
                            break;
                        }
                        case EVENT_LIGHTNING_RUSH_CHARGE:
                        {
                        Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me));
                            if (!unit)
                                unit = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                            if (unit)
                                DoCast(unit, SPELL_STORM_CHARGE);
                            break;
                        }
                        case EVENT_LIGHTNING_ROD:
                            Talk(RAND(SAY_LIGHT_NUKE_1, SAY_LIGHT_NUKE_2));
                            me->RemoveAura(SPELL_LIGHTNING_RUSH);
                            DoCast(me, SPELL_LIGHTNING_ROD);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_wushoolayAI(creature);
        }
};

void AddSC_boss_wushoolay()
{
    new boss_wushoolay();
}