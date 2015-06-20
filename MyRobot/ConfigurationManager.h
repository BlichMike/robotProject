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
	int startLocationX;
	int startLocationY;
	int startLocationYaw;
	int goalX;
	int goalY;
	int robotSizeX;
	int robotSizeY;
	float mapResolutionCM;
	float gridResolutionCM;
	static ConfigurationManager *single;
	ConfigurationManager()
	{
		// private Constructor
	}

public:
	static ConfigurationManager* getInstance();
	bool readConfigFile(string fileName);
	string getMap();
	int getStartLocationX();
	int getStartLocationY();
	int getStartLocationYaw();
	int getGoalX();
	int getGoalY();
	int getRobotSizeX();
	int getRobotSizeY();
	float getMapResolutionCM();
	float getGridResolutionCM();

	~ConfigurationManager()
	{
	}
};

} /* namespace std */

#endif /* CONFIGURATIONMANAGER_H_ */


