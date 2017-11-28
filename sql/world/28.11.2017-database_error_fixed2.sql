-- world staring error fixed part1
-- By Inc for Stormscale.Ru
-- in World DataBase.


INSERT INTO `creature_equip_template` (`entry`, `id`) VALUES ('35234', '1');

UPDATE `creature` SET `equipment_id`='1' WHERE (`guid`='35234');