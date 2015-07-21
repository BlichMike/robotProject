#include "GoForward.h"

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
	int robotCurX = robot->robotPositionX;
	int robotCurY = robot->robotPositionY;
	int destWayPointX = robot->currDestX;
	int destWayPointY = robot->CurrDestY;
	bool xEqual = robotCurX == destWayPointX;
	bool yEqual = robotCurY == destWayPointY;
	if(!xEqual || !yEqual)
		robot->setRobotSpeed(0.4,0.0);
	while (!(yEqual && xEqual))
	{
		xEqual = robotCurX == destWayPointX;
		yEqual = robotCurY == destWayPointY;
	}
	robot->setRobotSpeed(0.0,0.0);
}
