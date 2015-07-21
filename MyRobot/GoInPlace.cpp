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
	int destWayPointAngl = robot->curDestAngl;
	//Will stop when the deg is right;
	bool keepTurnning = robot->getYaw() != destWayPointAngl;
	if(keepTurnning)
		robot->setRobotSpeed(0.0,1.0);
	while(keepTurnning){
		robot->refreshLaserScan();
		cout <<  robot->getYaw();
		keepTurnning = robot->getYaw() != destWayPointAngl;
	}
	robot->setRobotSpeed(0.0,0.0);
}
