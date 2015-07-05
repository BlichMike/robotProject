/*
 * ConfigurationManager.h
 *
 *  Created on: Jun 19, 2015
 *      Author: colman
 */

#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_

#include <string>

namespace std {

class ConfigurationManager {

private:
	string map;
	float startLocationX;
	float startLocationY;
	float startLocationYaw;
	float goalX;
	float goalY;
	float robotSizeX;
	float robotSizeY;
	float mapResolutionCM;
	float gridResolutionCM;
	static ConfigurationManager *single;

public:
	static ConfigurationManager* getInstance();
	bool readConfigFile(string fileName);
	string getMap();
	float getStartLocationX();
	float getStartLocationY();
	float getStartLocationYaw();
	float getGoalX();
	float getGoalY();
	float getRobotSizeX();
	float getRobotSizeY();
	float getMapResolutionCM();
	float getGridResolutionCM();
	ConfigurationManager()
	{

	}

	~ConfigurationManager()
	{
	}
};

} /* namespace std */

#endif /* CONFIGURATIONMANAGER_H_ */


