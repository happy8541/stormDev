-- ----------------------------11--
-- Table structure for `world_tournaments`
-- ----------------------------
DROP TABLE IF EXISTS `world_tournaments`;
CREATE TABLE `world_tournaments` (
  `entry` int(11) NOT NULL,
  `level` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `time_limit` int(11) NOT NULL DEFAULT '0',
  `say_start` int(11) unsigned NOT NULL DEFAULT '0',
  `say_win` int(11) unsigned NOT NULL DEFAULT '0',
  `say_lose` int(10) unsigned NOT NULL DEFAULT '0',
  `chest_id` int(10) unsigned NOT NULL DEFAULT '0',
  `point_id` int(10) unsigned NOT NULL DEFAULT '0',
  `req_quest_id` int(10) unsigned NOT NULL DEFAULT '0',
  `kill_credit` int(10) unsigned NOT NULL DEFAULT '0',
  `menu_string` int(10) unsigned NOT NULL DEFAULT '0',
  `comment` varchar(255) NOT NULL,
  PRIMARY KEY (`entry`,`level`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of world_tournaments
-- ----------------------------
INSERT INTO `world_tournaments` VALUES ('100124', '1', '30000', '0', '0', '0', '2850', '1', '0', '0', '0', 'Npc 100124, level 1, limit 30 sec.');
INSERT INTO `world_tournaments` VALUES ('100124', '2', '20000', '0', '0', '0', '3715', '1', '0', '0', '0', 'Npc 100124, level 2, limit 20 sec.');

-- ----------------------------
-- Table structure for `world_tournament_points`
-- ----------------------------
DROP TABLE IF EXISTS `world_tournament_points`;
CREATE TABLE `world_tournament_points` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `map_id` int(10) unsigned NOT NULL DEFAULT '0',
  `x` float NOT NULL DEFAULT '0',
  `y` float NOT NULL DEFAULT '0',
  `z` float NOT NULL DEFAULT '0',
  `o` float NOT NULL DEFAULT '0',
  `comment` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of world_tournament_points
-- ----------------------------
INSERT INTO `world_tournament_points` VALUES ('1', '0', '-13218', '249', '22', '1.34', 'Gurubashi Enter');
INSERT INTO `world_tournament_points` VALUES ('2', '0', '-13205', '275', '22', '4.37', 'Gurubashi Center');

-- ----------------------------
-- Table structure for `world_tournament_creature`
-- ----------------------------
DROP TABLE IF EXISTS `world_tournament_creature`;
CREATE TABLE `world_tournament_creature` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `tournament_entry` int(10) unsigned NOT NULL DEFAULT '0',
  `tournament_level` int(10) unsigned NOT NULL DEFAULT '0',
  `entry` int(10) unsigned NOT NULL DEFAULT '0',
  `count` int(10) unsigned NOT NULL DEFAULT '0',
  `from_point_id` int(10) unsigned NOT NULL DEFAULT '0',
  `to_point_id` int(10) unsigned NOT NULL DEFAULT '0',
  `time` int(10) unsigned NOT NULL DEFAULT '0',
  `comment` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of world_tournament_creature
-- ----------------------------
INSERT INTO `world_tournament_creature` VALUES ('1', '100124', '1', '15931', '1', '1', '2', '0', 'Tour. 100124, level 1, npc: Grobbulus');
INSERT INTO `world_tournament_creature` VALUES ('2', '100124', '2', '6', '1', '1', '2', '0', 'Tour. 100124, level 2, npc: Kobold');
