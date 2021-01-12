# Host: localhost  (Version: 5.5.25a)
# Date: 2021-01-10 13:34:26
# Generator: MySQL-Front 5.3  (Build 4.13)

/*!40101 SET NAMES utf8 */;

#
# Source for table "student"
#

DROP TABLE IF EXISTS `student`;
CREATE TABLE `student` (
  `stuid` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `sex` tinyint(1) DEFAULT NULL,
  `age` int(3) DEFAULT NULL,
  PRIMARY KEY (`stuid`)
) ENGINE=InnoDB AUTO_INCREMENT=41824098 DEFAULT CHARSET=utf8;

#
# Data for table "student"
#

INSERT INTO `student` VALUES (1,'LJH',0,18),(2,'ffff',0,18),(3,'lxy',1,20);

#
# Source for table "subject"
#

DROP TABLE IF EXISTS `subject`;
CREATE TABLE `subject` (
  `subid` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`subid`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

#
# Data for table "subject"
#

INSERT INTO `subject` VALUES (1,'Chinese'),(2,'math');

#
# Source for table "r_stu_sub"
#

DROP TABLE IF EXISTS `r_stu_sub`;
CREATE TABLE `r_stu_sub` (
  `subid` int(11) NOT NULL DEFAULT '0',
  `stuid` int(11) NOT NULL DEFAULT '0',
  `grade` int(11) DEFAULT NULL,
  PRIMARY KEY (`subid`,`stuid`),
  KEY `FK_stu` (`stuid`),
  CONSTRAINT `FK_stu` FOREIGN KEY (`stuid`) REFERENCES `student` (`stuid`),
  CONSTRAINT `FK_sub` FOREIGN KEY (`subid`) REFERENCES `subject` (`subid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Data for table "r_stu_sub"
#

INSERT INTO `r_stu_sub` VALUES (1,1,100);
