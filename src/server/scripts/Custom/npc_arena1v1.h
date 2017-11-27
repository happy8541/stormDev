/*
 *TER-Server
 */

#ifndef ARENA_1V1_H
#define ARENA_1V1_H

const uint32 FORBIDDEN_TALENTS_IN_1V1_ARENA[] =
{
    // Healer
    201, // PriestDiscipline
    202, // PriestHoly
    382, // PaladinHoly
    262, // ShamanRestoration
    282, // DruidRestoration

    // Tanks
    //383, // PaladinProtection
    //163, // WarriorProtection

    0 // End
};

static bool Arena1v1CheckTalents(Player* player)
{
    if(!player)
        return false;

    if(sWorld->getBoolConfig(CONFIG_ARENA_1V1_BLOCK_FORBIDDEN_TALENTS) == false)
        return true;

    uint32 count = 0;
    for (uint32 talentId = 0; talentId < sTalentStore.GetNumRows(); ++talentId)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);

        if (!talentInfo)
            continue;

        for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
        {
            if (talentInfo->RankID[rank] == 0)
                continue;

            if (player->HasTalent(talentInfo->RankID[rank], player->GetActiveSpec()))
            {
                for(int8 i = 0; FORBIDDEN_TALENTS_IN_1V1_ARENA[i] != 0; i++)
                    if(FORBIDDEN_TALENTS_IN_1V1_ARENA[i] == talentInfo->TalentTab)
                        count += rank + 1;
            }
        }
    }

    if(count >= 36)
	{
//        ChatHandler(player->GetSession()).SendSysMessage("Вы не можете вступить, потому что вы вложили слишком много очков в запретный талант. Пожалуйста, отредактируйте свои таланты.");
        return false;
    }
    else
        return true;
}

#endif