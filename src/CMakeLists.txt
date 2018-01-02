# Copyright (C) 2017-2018 TrinityCore <http://www.trinitycore.org/>
# Copyright (C) Stormscale.Ru Cataclysm WoW-Emulator 4.3.4 With custom Code.
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_subdirectory(genrev)
add_subdirectory(server)

if(TOOLS)
  add_subdirectory(tools)
endif(TOOLS)

