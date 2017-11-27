#include "ScriptPCH.h"
#include "ScriptMgr.h"

#define CONST_HONOR_23 29434 //предмет который будет стоить
#define CONST_HONOR_233 50  //сколько надо штук 

#define MSG_GOSSIP_TEXT_MAIN_MENU "<- [Вернутся в Главное меню]"
#define MSG_GOSSIP_TEXT_NEXT_3 "[страница] ->"

class npc_titles : public CreatureScript
{
	public: 
	npc_titles() : CreatureScript("npc_titles") { }

		bool OnGossipHello(Player *player, Creature *_creature)
				{ 
			player->PlayerTalkClass->ClearMenus();
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Король Лич", GOSSIP_SENDER_MAIN, 711);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Огонек", GOSSIP_SENDER_MAIN, 712);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Лорд Каззак", GOSSIP_SENDER_MAIN, 713);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Леокк", GOSSIP_SENDER_MAIN, 714);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Таддиус", GOSSIP_SENDER_MAIN, 715);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Прелесть", GOSSIP_SENDER_MAIN, 716);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Паук", GOSSIP_SENDER_MAIN, 717);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Сапфирон", GOSSIP_SENDER_MAIN, 718);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Нот Чумной", GOSSIP_SENDER_MAIN, 719);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Кель Тузед", GOSSIP_SENDER_MAIN, 720);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "КельТалас", GOSSIP_SENDER_MAIN, 721);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Ктун", GOSSIP_SENDER_MAIN, 722);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Тралл", GOSSIP_SENDER_MAIN, 723);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Сильвана", GOSSIP_SENDER_MAIN, 724);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Алекстраза(человек)", GOSSIP_SENDER_MAIN, 725);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Король Ринн", GOSSIP_SENDER_MAIN, 726);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Молганис", GOSSIP_SENDER_MAIN, 727);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Алекстраза(дракон)", GOSSIP_SENDER_MAIN, 728);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Сакролаш", GOSSIP_SENDER_MAIN, 729);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_NEXT_3, GOSSIP_SENDER_MAIN, 748);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_creature->GetGUID());
						  return true;

}

		bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 action )
				{
				  switch (action)
		{
			 case 711: 
	   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(30721);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.8f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 712: 
			if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(12432);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 713: 
			if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(17887);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.10f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 714: 
		   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(20964);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 715: 
		   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(16137);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.4f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 716: 
		   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(16064);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 717:
		   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(15928);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.15f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 718: 
			if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(16033);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 719:
		   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(16590);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.7f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 720: 
			if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(15945);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.3f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 721:
	   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{       
			player->SetDisplayId(20023);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 722:      
	   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{    
			player->SetDisplayId(15786);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 723:
	   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(4527);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 724:
			if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(28213);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
		case 725:
			if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(28227);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true); 
		   player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.9f);
		   player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 726:
		   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(28127);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 727:
			if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(28220);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.6f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 728:
	  if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(27569);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 729:
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(23177);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
			case 730: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(26623);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 731: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(25286);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 732: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(27511);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.5f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 733: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(27573);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.8f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 734: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(27537);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 735: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(12818);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 736: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(25241);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.6f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 737: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(775);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 738: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(29099);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 739: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(29114);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.3f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 740: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(11650);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.5f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 741: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(17035);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 742: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(6351);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.7f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 743: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(18038);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 744: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(18058);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
		case 745: 
		 if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(18916);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.3f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
		case 746: 
		  if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(17715);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.7f);
			player->CLOSE_GOSSIP_MENU();
			}
			break; 
			case 747:
			player->PlayerTalkClass->ClearMenus();
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Король Лич", GOSSIP_SENDER_MAIN, 711);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Огонек", GOSSIP_SENDER_MAIN, 712);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Лорд Каззак", GOSSIP_SENDER_MAIN, 713);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Леокк", GOSSIP_SENDER_MAIN, 714);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Таддиус", GOSSIP_SENDER_MAIN, 715);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Прелесть", GOSSIP_SENDER_MAIN, 716);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Паук", GOSSIP_SENDER_MAIN, 717);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Сапфирон", GOSSIP_SENDER_MAIN, 718);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Нот Чумной", GOSSIP_SENDER_MAIN, 719);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Кель Тузед", GOSSIP_SENDER_MAIN, 720);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "КельТалас", GOSSIP_SENDER_MAIN, 721);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Ктун", GOSSIP_SENDER_MAIN, 722);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Тралл", GOSSIP_SENDER_MAIN, 723);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Сильвана", GOSSIP_SENDER_MAIN, 724);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Алекстраза(человек)", GOSSIP_SENDER_MAIN, 725);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Король Ринн", GOSSIP_SENDER_MAIN, 726);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Молганис", GOSSIP_SENDER_MAIN, 727);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Алекстраза(дракон)", GOSSIP_SENDER_MAIN, 728);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Сакролаш", GOSSIP_SENDER_MAIN, 729);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_NEXT_3, GOSSIP_SENDER_MAIN, 748);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_creature->GetGUID());
				 break;   
		  case 748:
			player->PlayerTalkClass->ClearMenus();
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Утгард Воин", GOSSIP_SENDER_MAIN, 730);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Упырь", GOSSIP_SENDER_MAIN, 731);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Скелет", GOSSIP_SENDER_MAIN, 732);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Скелет 2", GOSSIP_SENDER_MAIN, 733);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Скелет 3", GOSSIP_SENDER_MAIN, 734);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Пудж", GOSSIP_SENDER_MAIN, 735);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Скелет 4", GOSSIP_SENDER_MAIN, 736);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Вестник Смерти", GOSSIP_SENDER_MAIN, 737);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Рыцарь Смерти", GOSSIP_SENDER_MAIN, 738);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Маг серебряного авангарда", GOSSIP_SENDER_MAIN, 739);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Голум", GOSSIP_SENDER_MAIN, 740);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Красный бес", GOSSIP_SENDER_MAIN, 741);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Древень", GOSSIP_SENDER_MAIN, 742);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Синий бес", GOSSIP_SENDER_MAIN, 743);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Огр", GOSSIP_SENDER_MAIN, 744);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Демон Голова", GOSSIP_SENDER_MAIN, 745);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Дреней Красные доспехи", GOSSIP_SENDER_MAIN, 746);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_NEXT_3, GOSSIP_SENDER_MAIN, 749);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_MAIN_MENU, GOSSIP_SENDER_MAIN, 747);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_creature->GetGUID());
				 break;
				 case 749:
			player->PlayerTalkClass->ClearMenus();
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Гидра", GOSSIP_SENDER_MAIN, 750);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Колосс", GOSSIP_SENDER_MAIN, 751);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Бес феолетовый", GOSSIP_SENDER_MAIN, 752);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Красный Орк", GOSSIP_SENDER_MAIN, 753);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Занзилл Чумной", GOSSIP_SENDER_MAIN, 754);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Волк", GOSSIP_SENDER_MAIN, 755);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Подобие Матери БТ", GOSSIP_SENDER_MAIN, 756);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Эльф Красные доспехи", GOSSIP_SENDER_MAIN, 757);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Злобень", GOSSIP_SENDER_MAIN, 758);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Призрак человека", GOSSIP_SENDER_MAIN, 759);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Мароуз", GOSSIP_SENDER_MAIN, 760);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Злобный призрак", GOSSIP_SENDER_MAIN, 761);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_NEXT_3, GOSSIP_SENDER_MAIN, 748);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_MAIN_MENU, GOSSIP_SENDER_MAIN, 747);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_creature->GetGUID());
				 break;
				 case 750: 
	   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(18314);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 751: 
			if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(19687);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 752: 
			if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(17695);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 753: 
		   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(17052);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 754: 
		   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(22124);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 755: 
		   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(20046);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.3f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 756:
		   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(19586);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 757: 
			if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(22786);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 758:
		   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(22976);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 759: 
			if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{
			player->SetDisplayId(16042);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 760:
	   if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{       
			player->SetDisplayId(16540);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.7f);
			player->CLOSE_GOSSIP_MENU();
			}
			break;
	   case 761:      
	      if(player->HasItemCount(CONST_HONOR_23, CONST_HONOR_233))
			{    
			player->SetDisplayId(19329);
			player->DestroyItemCount(CONST_HONOR_23, CONST_HONOR_233, true);
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.4f);
			player->CLOSE_GOSSIP_MENU();
			}
            break;   
}
		
				  return true;
		}
};
void AddSC_npc_titles()
{
	new npc_titles;
}
