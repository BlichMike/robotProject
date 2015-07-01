/*
 * ConfigurationManager.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: colman
 */

#include "ConfigurationManager.h"
#include <stdlib.h>
#include <fstream>
#include <string>
#include<iostream>
#include<sstream>

namespace std {
ConfigurationManager* ConfigurationManager::single = NULL;

ConfigurationManager* ConfigurationManager::getInstance()
{
    if(!single)
    {
        single = new ConfigurationManager();
    }

    return single;
}

bool ConfigurationManager::readConfigFile(string fileName)
{
	string line;
	ifstream myfile (fileName.c_str());
	if (myfile.is_open())
	  {
		string mapLine;
		string startLocationLine;
		string goalLine;
		string robotSizeLine;
		string mapResolutionCMLine;
		string gridResolutionCMLine;
		getline(myfile,mapLine);
		getline(myfile,startLocationLine);
		getline(myfile,goalLine);
		getline(myfile,robotSizeLine);
		getline(myfile,mapResolutionCMLine);
		getline(myfile,gridResolutionCMLine);

		this->map = mapLine.substr(mapLine.find('~') + 1);
		this->map.erase(this->map.length() - 1);
		startLocationLine = startLocationLine.substr(startLocationLine.find(' '));
		stringstream location(startLocationLine);
		location >> (this->startLocationX) >> (this->startLocationY) >> (this->startLocationYaw);
		goalLine = goalLine.substr(goalLine.find(' '));
		stringstream line(goalLine);
		line >> (this->goalX) >> (this->goalY);
		robotSizeLine = robotSizeLine.substr(robotSizeLine.find(' '));
		stringstream robotSize(robotSizeLine);
		robotSize >> (this->robotSizeX) >> (this->robotSizeY);
		mapResolutionCMLine = mapResolutionCMLine.substr(mapResolutionCMLine.find(' '));
		stringstream mapResolutionCM(mapResolutionCMLine);
		mapResolutionCM >> (this->mapResolutionCM);
		gridResolutionCMLine = gridResolutionCMLine.substr(gridResolutionCMLine.find(' '));
		stringstream gridResolutionCM(gridResolutionCMLine);
		gridResolutionCM >> (this->gridResolutionCM);

	    myfile.close();
	    return true;
	  }

	  else
	  {
		  cout << "Unable to open file";
		  return false;
	  }
}

string ConfigurationManager::getMap()
{
	return this->map;
}

float ConfigurationManager::getStartLocationX()
{
	return this->startLocationX;
}

float ConfigurationManager::getStartLocationY()
{
	return this->startLocationY;
}

float ConfigurationManager::getStartLocationYaw()
{
	return this->startLocationYaw;
}

float ConfigurationManager::getGoalX()
{
	return this->goalX;
}

float ConfigurationManager::getGoalY()
{
	return this->goalY;
}

float ConfigurationManager::getRobotSizeX()
{
	return this->robotSizeX;
}

float ConfigurationManager::getRobotSizeY()
{
	return this->robotSizeY;
}

float ConfigurationManager::getMapResolutionCM()
{
	return this->mapResolutionCM;
}

float ConfigurationManager::getGridResolutionCM()
{
	return this->gridResolutionCM;
}

} /* namespace std */


