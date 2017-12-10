UPDATE `creature_template` SET `ScriptName` = 'boss_high_priestess_azil' WHERE `entry` = '42333';
UPDATE `creature_template` SET `ScriptName` = 'event_npc_icelord' WHERE `entry` = '777801';
UPDATE `creature_template` SET `ScriptName` = 'event_npc_earthlord' WHERE `entry` = '777802';
UPDATE `creature_template` SET `ScriptName` = 'event_npc_darklord' WHERE `entry` = '777803';
UPDATE `creature_template` SET `ScriptName` = 'event_mage_ice' WHERE `entry` = '777804';
UPDATE `creature_template` SET `ScriptName` = 'event_mage_fire' WHERE `entry` = '777805';
UPDATE `creature_template` SET `ScriptName` = 'event_dk' WHERE `entry` = '777806';
UPDATE `creature_template` SET `ScriptName` = 'event_warrior' WHERE `entry` = '777807';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('79249', 'spell_gravity_well_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('79332', 'spell_gravity_well_pull');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('80511', 'spell_seismic_shard');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('79014', 'spell_seismic_shard_change_seat');
UPDATE `spell_script_names` SET `spell_id`='79200', `ScriptName`='spell_summon_wave_south' WHERE (ISNULL(`spell_id`)) AND (ISNULL(`ScriptName`)) LIMIT 1
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('79196', 'spell_summon_wave_west');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96306', 'spell_grilek_pursuit_buff_state');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96631', 'spell_grilek_pursuit');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('97036', 'spell_sunder_rift_visual');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('97597', 'spell_spirit_warriors_gaze');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96644', 'spell_thousand_blades_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96645', 'spell_thousand_blades_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96680', 'spell_venomous_effusion_summon');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96475', 'spell_toxic_link_selector');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96476', 'spell_toxic_link_visual');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96653', 'spell_venom_withdrawal');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96342', 'spell_pursuit_fixate');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96434', 'spell_zanzils_graveyard_gas_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('96331', 'spell_frostburn_formula');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('104905', 'spell_perotharn_drain_essence');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('104906', 'spell_perotharn_drain_essence_dmg');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('102465', 'spell_queen_azshara_coldflame');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('79200', 'spell_summon_wave_south');
UPDATE `spell_script_names` SET `spell_id`='79244' WHERE (ISNULL(`spell_id`)) AND (`ScriptName`='spell_gravity_well_damage_nearby') LIMIT 1
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES ('18618', '11', '0', '0', 'achievement_lazy_eye');
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES ('939', '0', 'instance_well_of_eternity', '1');
/* If U have Script name in DATAbase - u need update */
UPDATE `instance_template` SET `script`='instance_well_of_eternity' WHERE (`map`='939');
