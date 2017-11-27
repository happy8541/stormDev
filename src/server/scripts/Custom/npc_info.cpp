/*
<--------------------------------------------------------------------------->
 - Developer(s): Inc,decipe
 - Complete: %100
 - ScriptName: 'Ingame Support NPC(npc_info)'
 - Comment: N/A
<--------------------------------------------------------------------------->
*/
#include "ScriptPCH.h"
 
class npc_info : public CreatureScript
{
        public:
                npc_info() : CreatureScript("npc_info")
                {
                }
 
                bool OnGossipHello(Player * pPlayer, Creature * pCreature)
                {
                        pPlayer->ADD_GOSSIP_ITEM(4, "С чего начать игру?", GOSSIP_SENDER_MAIN, 0);
                        pPlayer->ADD_GOSSIP_ITEM(4, "Прокачал персонажа, что далее?", GOSSIP_SENDER_MAIN, 1);
                        pPlayer->ADD_GOSSIP_ITEM(4, "Где же мне взять топ экипировку?", GOSSIP_SENDER_MAIN, 2);
                        pPlayer->ADD_GOSSIP_ITEM(4, "Где мне взять валюту сервера?", GOSSIP_SENDER_MAIN, 4);
                        pPlayer->ADD_GOSSIP_ITEM(0, "До свидания", GOSSIP_SENDER_MAIN, 3);
                        pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
                        return true;
                }
 
                bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
                {
                        if(!Player)
                                return true;
                       
                        switch(uiAction)
                        {
                                case 0: // This case will send the support message for "С чего начать игру?"
                                        {
                                                ChatHandler(Player->GetSession()).PSendSysMessage("Для начала, перед тобой стоит продавец с начальными вещами, попробуй одется. Далее у тебя во вкладке спутники есть карманный телепортер, ездовое животное. Телепортируйся в локацию, соответствующую твоему уровню и прокачивай персонажа.");
                                                Player->PlayerTalkClass->SendCloseGossip();
                                        }break;
                                case 1: // This case will send the support message for "Прокачал персонажа, что далее?"
                                        {
 
                                                ChatHandler(Player->GetSession()).PSendSysMessage("На нашем сервере, существует занижение игрового мира, соответственно экипировку можно достать не сложным способом. В столицах стоят продавцы начальной экипировки и различных реагентов.");
                                                Player->PlayerTalkClass->SendCloseGossip();
                                        }break;
                                case 2: // This case will send the support message for "Где же мне взять топ экипировку?"
                                        {
                                                ChatHandler(Player->GetSession()).PSendSysMessage("Весь остров Кель'Данас адаптирован под 80 уровень. Делай дейлики, различные квесты. Терасса магистров, Темный лабиринт, Логово груула, и другие адаптированные локации, позволяющие быстро одеть персонажа");
                                                Player->PlayerTalkClass->SendCloseGossip();
                                        }break;
                                case 4: // This case will send the support message for "Где мне взять валюту сервера?"
                                        {
                                                ChatHandler(Player->GetSession()).PSendSysMessage("Вся валюта находится в обменнике в главных столицах.Грань шторма - Мировые боссы, квесты, личный кабинет. Осколки правды - в большинстве своем можно получить за квесты и убийства мобов после телепорта в лагер Баш'ира.Частица солнца - падает с рарников на острове, используется как дополнительный источник золота. Доблестный знак победы - за убийства вражеских игроков. Концентрация злости - терасса магистров об, темный лабиринт об. Штормовая монета - Терасса магистров гер, темный лабиринт гер, Логово груула");
                                                Player->PlayerTalkClass->SendCloseGossip();
                                        }break;
                                case 3:
                                        {
                                                Player->PlayerTalkClass->SendCloseGossip();
                                        }break;
                        }
                        return true;
                }
 
};
void AddSC_npc_info()
{
        new npc_info();
}
