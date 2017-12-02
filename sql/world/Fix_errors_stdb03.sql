/* Update and Fixed STDB03
Only for Stormscale.Ru Cataclysm WoW-Emulator.
In STDBWORLD.

by Inc
*/

/*
апдейт нпс 42419;42454 отсутсвите АИ.
*/
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='42419')
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='42452')

/*
Отсутсвие String
ВНИМАНИЕ: Ренейм строчки, или-же ее отсутсвие приведет к крашу клиента!
*/
INSERT INTO `arkcore_string` (`entry`, `content_default`) VALUES ('29245', 'Stormscale.Ru Cataclysm WoW-Emulator');
