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



/* Delete unusing creature_addos */
 DELETE FROM creature_addon WHERE guid=61351;
 DELETE FROM creature_addon WHERE guid=61471;
 DELETE FROM creature_addon WHERE guid=61806;
 DELETE FROM creature_addon WHERE guid=62114;
 DELETE FROM creature_addon WHERE guid=62555;
 DELETE FROM creature_addon WHERE guid=62656;
 DELETE FROM creature_addon WHERE guid=62687;
 DELETE FROM creature_addon WHERE guid=62699;
 DELETE FROM creature_addon WHERE guid=63066;
 DELETE FROM creature_addon WHERE guid=63077;
 
 /* Insert NEW spells in WORLD */
 INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96914', 'spell_zanzili_fire');
 INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96338', 'spell_zanzils_graveyard_gas');
 