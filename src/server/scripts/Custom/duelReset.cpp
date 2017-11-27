/*
 
Duel Reset Script: 90%
 
TODO:
Remove mirror image / water elemental / Shadow Fiend / Feral Spirit / dk army / Force of Nature / Gargoyle on duel start.
 
*/
 
#include "ScriptPCH.h"
 
class Reset_OnDuelEnd : public PlayerScript
{
public:
    Reset_OnDuelEnd() : PlayerScript("Reset_OnDuelEnd") {}
 
    // Reset Warlocks / Hunters pet powers.
    void PetPowers(Player * player1)
    {
        Unit* pet = player1->GetGuardianPet();
 
        // Reset pet health.
        if (player1->GetPet())
            pet->SetHealth(pet->GetMaxHealth());
 
        // Reset pet powers.
        switch (player1->getClass())
        {
        case CLASS_WARLOCK:
            if (player1->GetPet())
                ((Guardian*)pet)->SetPower(POWER_MANA, pet->GetMaxPower(POWER_MANA));
            break;
        case CLASS_HUNTER:
            if (player1->GetPet())
                ((Guardian*)pet)->SetPower(POWER_FOCUS, pet->GetMaxPower(POWER_FOCUS));
            break;
        }
    }
 
    void DruidForm(Player * player1)
    {
        // Druid form.
        if (player1->getClass() == CLASS_DRUID)
            player1->SetPower(POWER_MANA, player1->GetMaxPower(POWER_MANA));
    }
 
    // Get player power type
    void GetPowers(Player * player1)
    {
        // Reset Health
        player1->SetHealth(player1->GetMaxHealth());
 
        switch (player1->getPowerType())
        {
        case POWER_RAGE:
            DruidForm(player1); // if player is in bear form reset mana.
            player1->SetPower(POWER_RAGE, 0);
            break;
        case POWER_ENERGY:
            DruidForm(player1); // if player is in cat form reset mana.
            player1->SetPower(POWER_ENERGY, player1->GetMaxPower(POWER_ENERGY));
            break;
        case POWER_RUNIC_POWER:
            player1->SetPower(POWER_RUNIC_POWER, 0);
            break;
        case POWER_MANA:
            PetPowers(player1); // Reset pet powers.
            player1->SetPower(POWER_MANA, player1->GetMaxPower(POWER_MANA));
            break;
        }
    }
 
    // Sets powers at duel start.
    void SetPowers(Player * player1)
    {
        switch (player1->getClass())
        {
        case CLASS_HUNTER:
        case CLASS_WARLOCK:
            // Reset Powers / Player/Pets Cooldowns.
            GetPowers(player1);
            player1->RemoveArenaSpellCooldowns(true);
            break;
        default:
            // Reset Cooldowns / Powers
            player1->RemoveArenaSpellCooldowns();
            GetPowers(player1);
            break;
        }
    }
 
    void OnDuelStart(Player * player, Player * player2)
    {
        // Check for duel area.
        if (player->GetAreaId() != 876) // 876 = GM Island
            return;
 
        // Auras
        uint32 Auras[] = { 498, 642, 10278, 11196, 25771, 41425, 57723, 57724,
            61987, 66233, 18499, 55694, 1719, 20230, 2687, 23920,
            2565, 871, 60503, 29842, 52437, 16491, 12292, 46916,
            50227, 65116, 58984, 59544, 33697, 26297, 54428, 1044,
            642, 1038, 61987, 31884, 20053, 57669, 59578, 48952,
            31821, 31842, 20216, 34027, 54216, 3045, 19263, 5384,
            34471, 6774, 26669, 11305, 31224, 14177, 63848, 13750,
            13877, 51713, 14278, 6346, 64844, 64904, 48111, 48068,
            586, 47930, 33206, 10060, 47788, 47858, 45529, 48792,
            49016, 49796, 49039, 51271, 50461, 49222, 2825, 30823,
            16166, 64701, 55166, 61295, 55277, 32182, 43010, 43012,
            45438, 12043, 57531, 12042, 12472, 11426, 18708, 47891,
            47241, 22812, 29166, 53312, 33357, 50213, 48505, 61336,
            58923, 17116 };
 
        // Remove auras
        for (uint32 aura : Auras)
        {
            player->RemoveAura(aura);
            player2->RemoveAura(aura);
        }
 
        // Set Powers / Reset Cooldowns.
        SetPowers(player);
        SetPowers(player2);
    }
 
    void OnDuelEnd(Player * pWinner, Player * pLooser, DuelCompleteType type)
    {
        // Restore Powers
        SetPowers(pWinner);
        SetPowers(pLooser);
    }
};
 
void AddSC_CdReset()
{
    new Reset_OnDuelEnd;
}