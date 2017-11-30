/*
 * Copyright (C) 2017 Stormscale.Ru Russian Community.
 * Скриптовка босса подземелья Зуллгуруб.
 * script complete %90
 * Need live test.
 * 
 * 
 * Recoded by Inc. Ferst code by Jook(complete ~40%).
 */
 
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulgurub.h"

enum Yells
{
    SAY_AGGRO               = 0,
    SAY_DEATH               = 1,
    SAY_DREAMSTATE_01       = 2, // Talk Dreamstate 1-3 only on using "Awaken Nightmares"
    SAY_DREAMSTATE_02       = 3,
    SAY_DREAMSTATE_03       = 4,
    SAY_PLAYER_KILL_01      = 5,
    SAY_PLAYER_KILL_02      = 6,
};

enum Spells
{
    SPELL_NIGHTMARES        = 96658, // Summon Adds (Triggered Spell of "Awaken Nightmares" 96670)
    SPELL_NIGHTMARE_SUM     = 96670,
    SPELL_EARTH_SHOCK       = 96650,
    SPELL_WRATH             = 96651,

    // Nightmare Illusions
    SPELL_CONSUME_SOUL      = 96758, // Kill Player instant
    SPELL_WAKING_NMARES     = 96757
};

enum Events
{
    EVENT_NIGHTMARES        = 0,
    EVENT_EARTH_SHOCK,
    EVENT_WRATH,
};

enum Adds
{
    NPC_NIGHTMARE_ILLUSION   = 52284
};

class boss_hazzarah : public CreatureScript
{
    public:
        boss_hazzarah() : CreatureScript("boss_hazzarah") { }

        struct boss_hazzarahAI : public BossAI
        {
            boss_hazzarahAI(Creature* creature) : BossAI(creature, DATA_HAZZARAH) { }

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
                events.ScheduleEvent(EVENT_WRATH, 2000);
                events.ScheduleEvent(EVENT_EARTH_SHOCK, 25000);
                events.ScheduleEvent(EVENT_NIGHTMARES, 55000);
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
                    Talk(RAND(SAY_PLAYER_KILL_01, SAY_PLAYER_KILL_02));
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
                        case EVENT_WRATH:
                            DoCastVictim(SPELL_WRATH);
                            events.ScheduleEvent(EVENT_WRATH, urand(2700, 5200));
                            break;
                        case EVENT_EARTH_SHOCK: // Only on active Victim
                            DoCastVictim(SPELL_EARTH_SHOCK);
                            events.ScheduleEvent(EVENT_EARTH_SHOCK, urand(20*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            break;
                        case EVENT_NIGHTMARES:
                            Talk(RAND(SAY_DREAMSTATE_01, SAY_DREAMSTATE_02, SAY_DREAMSTATE_03));
                            DoCast(me, SPELL_NIGHTMARES);
                            events.ScheduleEvent(EVENT_NIGHTMARES, urand(65*IN_MILLISECONDS, 70*IN_MILLISECONDS));
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_hazzarahAI(creature);
        }
};

class mob_nightmare_illusion : public CreatureScript
{
public:
    mob_nightmare_illusion() : CreatureScript("mob_nightmare_illusion") { }

    struct mob_nightmare_illusionAI : public ScriptedAI
    {
        mob_nightmare_illusionAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true); // handle this immunity mask coreside
        }

        void Reset()
        {
            targetGUID = 0;
            checkTargetTimer = 1000;
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoZoneInCombat();

            me->SetSpeed(MOVE_RUN, 0.3f);
            DoCastVictim(SPELL_WAKING_NMARES);

            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
            {
                me->ClearUnitState(UNIT_STATE_CASTING);
                me->GetMotionMaster()->MoveChase(target);
                targetGUID = target->GetGUID();
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if(!UpdateVictim())
                return;

            if (checkTargetTimer <= diff)
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, targetGUID))
				
                    if (me->GetDistance(player) < 1.3f)
                    {
                        DoCastVictim(SPELL_CONSUME_SOUL);
                        me->DespawnOrUnsummon(100); // we use here 100miliseconds, because its called in one time
                    }
                checkTargetTimer = 500; // we check the target every 500miliseconds
            }
            else checkTargetTimer -= diff;
        }
    private:
        uint64 targetGUID;
        uint32 checkTargetTimer;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_nightmare_illusionAI (creature);
    }
};

void AddSC_boss_hazzarah()
{
    new boss_hazzarah();
    new mob_nightmare_illusion();
}