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


	int robotCurX = (int)(robot->getXPos() * 100 / mapRes);
	int robotCurY = (int)(robot->getYPos() * 100 / mapRes);
	int startY = robotCurY;
	int destWayPointX = robot->currDestX;
	int destWayPointY = robot->CurrDestY;
	bool isGetTheDest = false;


	if ((robotCurX <= destWayPointX + 20) &&
		(robotCurX + 20 >= destWayPointX) &&
		(startY + (startY - robotCurY) <= destWayPointY + 20) &&
		(startY + (startY - robotCurY) + 20 >= destWayPointY))
	{
		isGetTheDest = true;
	}
	if (!isGetTheDest)
	{
		robot->setRobotSpeed(0.4,0.0);
	}

	while (!isGetTheDest)
	{
		robotCurX = (int)(robot->getXPos() * 100 / mapRes);
		robotCurY = (int)(robot->getYPos() * 100 / mapRes);
		robot->refreshLaserScan();

		//cout <<  robotCurX * 100 / mapRes << "," << mapHeight + (mapHeight/2 -robotCurY * 100 / mapRes) << " " <<  destWayPointX + 10 << ","  << destWayPointY + 10  << endl;
		//cout <<  robotCurX << "," << mapHeight - ( mapHeight - (startY + (startY - robotCurY)))<< " " <<  destWayPointX << ","  << destWayPointY  << endl;
		cout << (mapHeight  - startY) << " " <<  (mapHeight - robotCurY) << "*******************8" << endl;
		cout <<  robotCurX << "," << (mapHeight  - startY) + (mapHeight - robotCurY) << " " <<  destWayPointX << ","  << destWayPointY  << endl;
		// Check if got the point
		if ((robotCurX <= destWayPointX + 20) &&
			(robotCurX + 20 >= destWayPointX) &&
			(startY + (startY - robotCurY) <= destWayPointY + 20) &&
			(startY + (startY - robotCurY) + 20 >= destWayPointY))
			{
				isGetTheDest = true;
			}
	}

	robot->robotPositionX = robotCurX;
	robot->robotPositionY = robotCurY;
	robot->setRobotSpeed(0.0,0.0);
}
