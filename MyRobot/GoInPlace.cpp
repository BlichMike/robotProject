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
	bool keepTurnning = (int)(robot->getYaw()*100) != (int)(destWayPointAngl * M_PI / 180 * 100);
	if(keepTurnning)
		robot->setRobotSpeed(0.0,0.7);
	while(keepTurnning){
		robot->refreshLaserScan();
		cout << (int)(robot->getYaw()*100)  <<  "  "  <<  (int)(destWayPointAngl * M_PI / 180 * 100) << endl;
		if ((((int)(robot->getYaw()*100) <= (int)(destWayPointAngl * M_PI / 180 * 100)+10)) &&
		    ((int)(robot->getYaw()*100) +10 >= (int)(destWayPointAngl * M_PI / 180 * 100)))
		{
			keepTurnning = false;
		}
	}
	robot->setRobotSpeed(0.0,0.0);
}
