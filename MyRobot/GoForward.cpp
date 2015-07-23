#include "GoForward.h"
#include "ConfigurationManager.h"
#include "Map.h"

//C'Tor
GoForward::GoForward(Robot * robot):Behaviors(robot) {}

// renturn true
bool GoForward::startCondition()
{
	// move
	return true;
}

//check if to stop
bool GoForward::stopCondition()
{
	// move until we reach the next way point
	return true;
}

// action
void GoForward::action()
{

	ConfigurationManager *configFile;
	configFile = ConfigurationManager::getInstance();
	Map * m = new Map();
	int mapHeight = m->getHeight();
	double mapRes = configFile->getMapResolutionCM();

	double robotCurX = robot->getXPos();
	double robotCurY = robot->getYPos();
	double destWayPointX = robot->currDestX;
	double destWayPointY = robot->CurrDestY;
	bool isGetTheDest = false;

	if ((robotCurX * 100 / mapRes <= destWayPointX + 10) &&
		(robotCurX * 100 / mapRes + 10 <= destWayPointX) &&
		(mapHeight + (mapHeight/2 -robotCurY * 100 / mapRes) <= destWayPointY + 10) &&
		(mapHeight + (mapHeight/2 -robotCurY * 100 / mapRes) + 10 <= destWayPointY))
	{
		isGetTheDest = true;
	}
	if (!isGetTheDest)
	{
		robot->setRobotSpeed(0.3,0.0);
	}

	while (!isGetTheDest)
	{
		robotCurX = robot->getXPos();
		robotCurY = robot->getYPos();
		robot->refreshLaserScan();
		cout <<  robotCurX * 100 / mapRes << "," << mapHeight + (mapHeight/2 -robotCurY * 100 / mapRes) << " " <<  destWayPointX + 10 << ","  << destWayPointY + 10  << endl;

		// Check if got the point
		if ((robotCurX * 100 / mapRes <= destWayPointX + 20) &&
			(robotCurX * 100 / mapRes + 20 >= destWayPointX) &&
			(mapHeight + (mapHeight/2 -robotCurY * 100 / mapRes) <= destWayPointY + 20) &&
			(mapHeight + (mapHeight/2 -robotCurY * 100 / mapRes) + 20 >= destWayPointY))
			{
				isGetTheDest = true;
			}
	}
	robot->setRobotSpeed(0.0,0.0);
}
