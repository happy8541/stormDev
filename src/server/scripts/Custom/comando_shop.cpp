/*
 * Copyright (C) 2016 DeathCore <http://www.noffearrdeathproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
 
#include "ScriptPCH.h"
#include "Chat.h"
 
 
 
class buff_commandscript : public CommandScript
{
public:
    buff_commandscript() : CommandScript("buff_commandscript") { }
 
        ChatCommand* GetCommands() const
    {
        static ChatCommand IngameCommandTable[] =
        {     
                        { "shop",            SEC_PLAYER,  false, &HandleMallCommand,            "", NULL },
            { NULL,            0,                  false, NULL,                              "", NULL }
        };
                return IngameCommandTable;
    }
 
        
      
        static bool HandleMallCommand(ChatHandler * handler, const char * args)
    {
        Player * me = handler->GetSession()->GetPlayer();
      
                me-> TeleportTo(0, -2723.567871f, -5356.419434f, 177.281921f, 2.535085f);
                handler->PSendSysMessage("Вы успешно телепортированы в зону Магазина.");
                return true;
    }
};
 
void AddSC_Ingame_commandscript()
{
    new buff_commandscript();
}