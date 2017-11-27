#include "ScriptPCH.h"  
#include "AccountMgr.h"  
#include "Config.h" 

 class gm_hello : public PlayerScript  
 {  
 public:  
        gm_hello() : PlayerScript("gm_hello") {}  

     void OnLogin(Player* player)  
     {  
        
       if (player->GetSession()->GetSecurity() == SEC_MODERATOR)  
              {  
                  std::string sText = ("Модератор '|cFF60FF00" + std::string(player->GetSession()->GetPlayerName()) + "|r' входит в Игровой мир.");  
                  sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());  
              }  
if (player->GetSession()->GetSecurity() == SEC_TESTER)  
              {  
                  std::string sText = ("Тестер '|cFF60FF00" + std::string(player->GetSession()->GetPlayerName()) + "|r' входит в Игровой мир.");  
                  sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());  
              }
    if (player->GetSession()->GetSecurity() == SEC_GAMEMASTER)  
              {  
                  std::string sText = ("Эвент-мастер '|cFF60FF00" + std::string(player->GetSession()->GetPlayerName()) + "|r' входит в Игровой мир.");  
                  sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());  
              }  
    if (player->GetSession()->GetSecurity() == SEC_ADMINISTRATOR)  
              {  
                  std::string sText = ("Гейм-мастер '|cFF60FF00" + std::string(player->GetSession()->GetPlayerName()) + "|r' входит в Игровой мир.");  
                  sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());  
              } 
	if (player->GetSession()->GetSecurity() == SEC_CONSOLE)
	{
		std::string sText = ("Администратор Проэкта '|cFF60FF00" + std::string(player->GetSession()->GetPlayerName()) + "|r' входит в Игровой мир.");
		sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());
	}
    if (player->GetSession()->GetSecurity() == SEC_KURATOR)  
              {  
                  std::string sText = ("Куратор Проэкта '|cFF60FF00" + std::string(player->GetSession()->GetPlayerName()) + "|r' входит в Игровой мир.");  
                  sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());  
              }    
  }  
      
  void OnLogout(Player* player) 
  {   
       if (player->GetSession()->GetSecurity() == SEC_MODERATOR)  
              {  
                  std::string sText = ("Модератор '|cFF60FF00" + std::string(player->GetSession()->GetPlayerName()) + "|r' выходит из Игрового мира.");  
                  sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());  
              }  

if (player->GetSession()->GetSecurity() == SEC_TESTER)  
              {  
                  std::string sText = ("Тестер '|cFF60FF00" + std::string(player->GetSession()->GetPlayerName()) + "|r' выходит из Игрового мира.");  
                  sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());  
              } 
    if (player->GetSession()->GetSecurity() == SEC_GAMEMASTER)  
              {  
                  std::string sText = ("Эвент-мастер '|cFF60FF00" + std::string(player->GetSession()->GetPlayerName()) + "|r' выходит из Игрового мира.");  
                  sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());  
              }  
    if (player->GetSession()->GetSecurity() == SEC_ADMINISTRATOR)  
              {  
                  std::string sText = ("Гейм-мастер '|cFF60FF00" + std::string(player->GetSession()->GetPlayerName()) + "|r' выходит из Игрового мира.");  
                  sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());  
              } 
	if (player->GetSession()->GetSecurity() == SEC_CONSOLE)
	{
		std::string sText = ("Администратор Проэкта '|cFF60FF00" + std::string(player->GetSession()->GetPlayerName()) + "|r' выходит из Игрового мира.");
		sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());
	}
    if (player->GetSession()->GetSecurity() == SEC_KURATOR)  
              {  
                  std::string sText = ("Куратор Проэкта '|cFF60FF00" + std::string(player->GetSession()->GetPlayerName()) + "|r' выходит из Игрового мира.");  
                  sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());  
              } 
   }   
 };  

 void AddSC_gm_hello()  
 {  
        new gm_hello();  
 }
