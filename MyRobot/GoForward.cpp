#include "GoForward.h"
#include "ConfigurationManager.h"
#include "Map.h"

//C'Tor
GoForward::GoForward(Robot * robot):Behaviors(robot) {}

// renturn true
bool GoForward::startCondition()
{
	ConfigurationManager *configFile;
	configFile = ConfigurationManager::getInstance();
	double mapRes = configFile->getMapResolutionCM();
	int robotCurX = (int)(robot->getXPos() * 100 / mapRes);
	int robotCurY = (int)(robot->getYPos() * 100 / mapRes);
	int destWayPointX = robot->currDestX;
	int destWayPointY = robot->CurrDestY;
	bool isGetTheDest = true;

	robot->refreshLaserScan();

	if ((robotCurX + 10 >= destWayPointX) &&
		(robotCurX <= destWayPointX + 10 ) &&
		(robot->getRealYPos(robotCurY) + 10 >= destWayPointY) &&
		(robot->getRealYPos(robotCurY) <= destWayPointY + 10))
	{
		isGetTheDest = false;
	}

	// move
	return isGetTheDest;
}

//check if to stop
bool GoForward::stopCondition()
{
	ConfigurationManager *configFile;
	configFile = ConfigurationManager::getInstance();
	double mapRes = configFile->getMapResolutionCM();
	int robotCurX = (int)(robot->getXPos() * 100 / mapRes);
	int robotCurY = (int)(robot->getYPos() * 100 / mapRes);
	int destWayPointX = robot->currDestX;
	int destWayPointY = robot->CurrDestY;
	bool isGetTheDest = false;

	robot->refreshLaserScan();

	//cout <<  robotCurX << "," << robot->getRealYPos(robotCurY) << " " <<  destWayPointX << ","  << destWayPointY  << endl;

	cout <<  robotCurX << "," << robot->getRealYPos(robotCurY) << " " <<  destWayPointX << ","  << destWayPointY  << endl;
	// Check if got the point
	if ((robotCurX + 10 >= destWayPointX) &&
		(robotCurX <= destWayPointX + 10 ) &&
		(robot->getRealYPos(robotCurY) + 10 >= destWayPointY) &&
		(robot->getRealYPos(robotCurY) <= destWayPointY + 10))
	{
		isGetTheDest = true;
	}

	if (isGetTheDest)
	{
		robot->setRobotSpeed(0.0,0.0);
		robot->robotPositionX = destWayPointX;
		robot->robotPositionY = robot->getRobotYPos(destWayPointY);
	}
	// move until we reach the next way point
	return isGetTheDest;
}

// action
void GoForward::action()
{
	robot->setRobotSpeed(0.2,0.0);
}
