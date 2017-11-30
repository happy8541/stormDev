-- Start Develop STDB434.03 
-- By Inc (c) Stormscale.Ru.
-- Released 30.11.2017
-- Stormscale.Ru Developers - Inc;Declipe.

-- Риолит, правка скрипт-нейма, скорость перемещения.
UPDATE `creature_template` SET `speed_walk`= 0.5, `speed_run`= 0.5,`ScriptName` = 'boss_lord_rhyolith' WHERE `entry` = '52558'; 
UPDATE `creature_template` SET `speed_walk`= 0.5, `speed_run`= 0.5,`ScriptName` = 'npc_right_leg' WHERE `entry` = '53087';  
UPDATE `creature_template` SET `speed_walk`= 0.5, `speed_run`= 0.5,`ScriptName` = 'npc_left_leg' WHERE `entry` = '52577';    
UPDATE `world`.`creature_template` SET `VehicleId` = '1606' WHERE `entry` = '52558';

UPDATE `creature_template` SET `difficulty_entry_3` = '54080' WHERE `entry` = '53691'; 
UPDATE `creature_template` SET `minlevel` = '88' , `maxlevel` = '88' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `minlevel` = '88' , `maxlevel` = '88' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `minlevel` = '88' , `maxlevel` = '88' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `exp` = '3' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `exp` = '3' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `exp` = '3' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `faction_A` = '16' , `faction_H` = '16' WHERE `entry` = '53691'; 
UPDATE `creature_template` SET `faction_A` = '16' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `faction_A` = '16' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `faction_A` = '16' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `faction_H` = '16' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `faction_H` = '16' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `faction_H` = '16' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `speed_walk` = '3.2' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `speed_walk` = '3.2' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `speed_walk` = '3.2' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `speed_run` = '1.71429' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `speed_run` = '1.71429' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `speed_run` = '1.71429' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `mindmg` = '1225.5' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `mindmg` = '1225.5' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `mindmg` = '1225.5' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `maxdmg` = '1544.7' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `maxdmg` = '1544.7' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `maxdmg` = '1544.7' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `dmg_multiplier` = '8' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `dmg_multiplier` = '10' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `dmg_multiplier` = '11' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `dmg_multiplier` = '15' WHERE `entry` = '53691'; 
UPDATE `creature_template` SET `dmg_multiplier` = '16' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `dmg_multiplier` = '20' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `dmg_multiplier` = '22' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `dmg_multiplier` = '20' WHERE `entry` = '53691'; 
UPDATE `creature_template` SET `dmg_multiplier` = '22' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `dmg_multiplier` = '30' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `dmg_multiplier` = '33' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `baseattacktime` = '1500' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `baseattacktime` = '1500' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `baseattacktime` = '1500' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `rangeattacktime` = '2000' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `rangeattacktime` = '2000' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `rangeattacktime` = '2000' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `unit_flags` = '32768' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `unit_flags` = '32768' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `unit_flags` = '32768' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `dynamicflags` = '13' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `dynamicflags` = '13' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `dynamicflags` = '13' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `lootid` = '53979' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `lootid` = '54079' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `lootid` = '54080' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `Armor_mod` = '11977' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `Armor_mod` = '11977' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `Armor_mod` = '11977' WHERE `entry` = '54080'; 
UPDATE `creature_template` SET `mechanic_immune_mask` = '635387903' WHERE `entry` = '53979'; 
UPDATE `creature_template` SET `mechanic_immune_mask` = '635387903' WHERE `entry` = '54079'; 
UPDATE `creature_template` SET `mechanic_immune_mask` = '635387903' WHERE `entry` = '54080';


--Фикс репутации за убийство мобов--
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54402;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54401;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54367;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54348;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54299;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54277;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54276;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54275;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54274;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54161;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54143;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54073;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54020;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54019;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=54015;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53986;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53952;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53914;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53910;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53901;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53876;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53875;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53872;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53795;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53793;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53791;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53786;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53732;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53729;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53723;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53695;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53694;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53648;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53642;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53640;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53639;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53635;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53631;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53619;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53617;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53616;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53585;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53575;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53545;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53529;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53494;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53492;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53490;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53488;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53485;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53474;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53435;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53433;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53395;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53393;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53244;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53237;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53231;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53224;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53223;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53222;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53209;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53206;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53188;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53187;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53186;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53185;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53178;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53167;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53158;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53154;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53141;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53140;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53134;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53130;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53129;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53128;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53127;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53121;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53120;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53119;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53116;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53115;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53102;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53096;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53095;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53094;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=52672;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=52659;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=52571;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=52558;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=52498;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=52409;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=47242;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=45979;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=42098;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=35592;
DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=15214;
-- шэннокс

DELETE FROM `creature_onkill_reputation` WHERE  `creature_id`=53691;


INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54402, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54401, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54367, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54348, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54299, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54277, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54276, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54275, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54274, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54161, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54143, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54073, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54020, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54019, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (54015, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53986, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53952, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53914, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53910, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53901, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53876, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53875, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53872, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53795, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53793, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53791, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53786, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53732, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53729, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53723, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53695, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53694, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53648, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53642, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53640, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53639, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53635, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53631, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53619, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53617, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53616, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53585, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53575, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53545, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53529, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53494, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53492, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53490, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53488, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53485, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53474, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53435, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53433, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53395, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53393, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53244, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53237, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53231, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53224, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53223, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53222, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53209, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53206, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53188, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53187, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53186, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53185, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53178, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53167, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53158, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53154, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53141, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53140, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53134, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53130, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53129, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53128, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53127, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53121, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53120, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53119, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53116, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53115, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53102, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53096, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53095, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53094, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (52672, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (52659, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (52571, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (52558, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (52498, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (52409, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (47242, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (45979, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (42098, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (35592, 1204, 5, 30);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (15214, 1204, 5, 30);
-- шэннокс
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`) VALUES (53691, 1204, 7, 250);

-----Фикс иммунитета боссов----
Update `creature_template` SET `mechanic_immune_mask`=617299799 WHERE entry in (53691, 52409, 52571, 52558, 52498, 53494, 52530);
-----Blizzlike ХП боссов----
Update `creature_template` SET `exp`=3 WHERE entry in (53691, 52409, 52571, 52558, 52498, 53494, 52530);
Update `creature_template` SET health_mod=1130 WHERE entry=53691;
Update `creature_template` SET health_mod=2443 WHERE entry=52409;
Update `creature_template` SET health_mod=4276 WHERE entry=52571;
Update `creature_template` SET health_mod=775 WHERE entry=52558;
Update `creature_template` SET health_mod=974 WHERE entry=52498;
Update `creature_template` SET health_mod=1935 WHERE entry=53494;
Update `creature_template` SET health_mod=2295 WHERE entry=52530;

---Шэннокс вэйпоинты----
-- Shannox  (through Firelands)
DELETE FROM `waypoint_data` WHERE `id`= 154280940;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(154280940, 1, -241.456, 103.116, 47.8124, 0, 0, 0, 100, 0),
(154280940, 2, -271.088, 81.0518, 46.1824, 0, 0, 0, 100, 0),
(154280940, 3, -286.624, 72.0301, 46.1577, 0, 0, 0, 100, 0),
(154280940, 4, -317.144, 66.7632, 46.1577, 0, 0, 0, 100, 0),
(154280940, 5, -321.03, 43.0768, 46.1577, 0, 0, 0, 100, 0),
(154280940, 6, -305.882, 25.3226, 46.1577, 0, 0, 0, 100, 0),
(154280940, 7, -306.426, -2.57413, 46.1576, 0, 0, 0, 100, 0),
(154280940, 8, -316.167, -17.6987, 46.1576, 0, 0, 0, 100, 0),
(154280940, 9, -318.101, -32.8989, 46.1576, 0, 0, 0, 100, 0),
(154280940, 10, -321.495, -48.4758, 46.1576, 0, 0, 0, 100, 0),
(154280940, 11, -302.064, -74.2203, 46.1576, 0, 0, 0, 100, 0),
(154280940, 12, -299.831, -91.8059, 46.1576, 0, 0, 0, 100, 0),
(154280940, 13, -291.714, -109.743, 45.8785, 0, 0, 0, 100, 0),
(154280940, 14, -245.637, -172.116, 54.2827, 0, 0, 0, 100, 0),
(154280940, 15, -207.106, -214.714, 54.4089, 0, 0, 0, 100, 0),
(154280940, 16, -188.044, -236.142, 55.6893, 0, 0, 0, 100, 0),
(154280940, 17, -162.902, -236.733, 55.6823, 0, 0, 0, 100, 0),
(154280940, 18, -121.679, -205.623, 57.118, 0, 0, 0, 100, 0),
(154280940, 19, -112.426, -158.936, 57.0601, 0, 0, 0, 100, 0),
(154280940, 20, -77.8603, -116.232, 56.9446, 0, 0, 0, 100, 0),
(154280940, 21, -56.0388, -35.9044, 57.493, 0, 0, 0, 100, 0),
(154280940, 22, -35.8763, 57.4226, 56.416, 0, 0, 0, 100, 0),
(154280940, 23, -14.6843, 90.8993, 56.6997, 0, 0, 0, 100, 0),
(154280940, 24, 19.3909, 166.628, 46.1518, 0, 0, 0, 100, 0),
(154280940, 25, -5.42823, 199.746, 47.5595, 0, 0, 0, 100, 0),
(154280940, 26, -74.926, 172.977, 44.7473, 0, 0, 0, 100, 0),
(154280940, 27, -123.932, 192.076, 46.1569, 0, 0, 0, 100, 0),
(154280940, 28, -148.453, 189.73, 46.1569, 0, 0, 0, 100, 0),
(154280940, 29, -176.173, 174.809, 46.402, 0, 0, 0, 100, 0),
(154280940, 30, -189.397, 172.102, 46.6773, 0, 0, 0, 100, 0),
(154280940, 31, -235.357, 136.817, 49.1653, 0, 0, 0, 100, 0),
(154280940, 32, -241.792, 109.354, 48.2423, 0, 0, 0, 100, 0);


