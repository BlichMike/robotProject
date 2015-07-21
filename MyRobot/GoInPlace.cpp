#include "GoInPlace.h"

//C'Tor
GoInPlace::GoInPlace(Robot * robot):Behaviors(robot) {}

// turn in place
bool GoInPlace::startCondition()
{
	// return true only if u need to set new angel
	return true;
}

// stop turn in place
bool GoInPlace::stopCondition()
{
	return true;
}

// action
void GoInPlace::action()
{
	int curRobotAngl = robot->robotPositionYaw;
	int destWayPointAngl = robot->curDestAngl;
	//Will stop when the deg is right;
	bool keepTurnning = curRobotAngl != destWayPointAngl;
	if(keepTurnning)
		robot->setRobotSpeed(0.0,1.0);
	while(keepTurnning){
		keepTurnning = curRobotAngl != destWayPointAngl;
	}
	robot->setRobotSpeed(0.0,0.0);
}
