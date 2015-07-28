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

	if (robot->curDestAngl==0)
	{
		if ((robotCurX <= destWayPointX +10) &&
			(robotCurX >= destWayPointX +30))
		{
			isGetTheDest = false;
		}
	}
	if (robot->curDestAngl == 45)
	{

	}
	if (robot->curDestAngl==90)
	{
		if ((robot->getRealYPos(robotCurY) <= destWayPointY - 20) &&
			(robot->getRealYPos(robotCurY) >= destWayPointY - 40))
		{
			isGetTheDest = false;
		}

	}
	if (robot->curDestAngl == 135)
	{
		if ((robotCurX <= destWayPointX -20) &&
		(robotCurX >= destWayPointX - 40) &&
		(robot->getRealYPos(robotCurY) <= destWayPointY - 20) &&
		(robot->getRealYPos(robotCurY) >= destWayPointY - 40))
		{
			isGetTheDest = false;
		}

	}
	if (robot->curDestAngl==180)
	{
		if ((robotCurX <= destWayPointX -40) &&
			(robotCurX >= destWayPointX -60))
		{
			isGetTheDest = false;
		}
	}
	if (robot->curDestAngl == 225)
	{

	}
	if (robot->curDestAngl==270)
	{
		if ((robot->getRealYPos(robotCurY) <= destWayPointY + 20) &&
			(robot->getRealYPos(robotCurY) >= destWayPointY + 40))
		{
			isGetTheDest = false;
		}
	}
	if (robot->curDestAngl == 315)
	{

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
	/*if ((robotCurX + 10 >= destWayPointX) &&
		(robotCurX <= destWayPointX + 10 ) &&
		(robot->getRealYPos(robotCurY) + 10 >= destWayPointY) &&
		(robot->getRealYPos(robotCurY) <= destWayPointY + 10))
	{
		isGetTheDest = true;
	}
	*/

	if (robot->curDestAngl==0)
	{
		if ((robotCurX <= destWayPointX +10) &&
			(robotCurX >= destWayPointX +30))
		{
			isGetTheDest = true;
		}
	}
	if (robot->curDestAngl == 45)
	{

	}
	if (robot->curDestAngl==90)
	{
		if ((robot->getRealYPos(robotCurY) <= destWayPointY - 20) &&
			(robot->getRealYPos(robotCurY) >= destWayPointY - 40))
		{
			isGetTheDest = true;
		}

	}
	if (robot->curDestAngl == 135)
	{
		if ((robotCurX <= destWayPointX -15) &&
			(robotCurX >= destWayPointX - 40) &&
			(robot->getRealYPos(robotCurY) <= destWayPointY -15) &&
			(robot->getRealYPos(robotCurY) >= destWayPointY - 40))
		{
			isGetTheDest = true;
		}

	}
	if (robot->curDestAngl ==180)
	{
		if ((robotCurX <= destWayPointX - 50) &&
			(robotCurX >= destWayPointX - 70))
		{
			isGetTheDest = true;
		}
	}
	if (robot->curDestAngl == 225)
	{

	}
	if (robot->curDestAngl==270)
	{
		if ((robot->getRealYPos(robotCurY) <= destWayPointY + 20) &&
			(robot->getRealYPos(robotCurY) >= destWayPointY + 40))
		{
			isGetTheDest = true;
		}
	}
	if (robot->curDestAngl == 315)
	{

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
