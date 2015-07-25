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
	bool keepTurnning = true;
	if ((((int)(robot->getYaw()*100) <= (int)(destWayPointAngl * M_PI / 180 * 100)+5)) &&
	     ((int)(robot->getYaw()*100)+5 >= (int)(destWayPointAngl * M_PI / 180 * 100)))
	{
		keepTurnning = false;
	}
	if(keepTurnning)
		robot->setRobotSpeed(0.0,0.3);
	while(keepTurnning){
		robot->refreshLaserScan();

		if (robot->getYaw() > 0 )
		{
			cout << (int)(robot->getYaw() * 180 / M_PI)  <<  "  "  <<  destWayPointAngl << endl;
			if (((int)(robot->getYaw()*180 / M_PI) <= destWayPointAngl + 5) &&
			     ((int)(robot->getYaw()*180 / M_PI) +5 >= destWayPointAngl))
			{
				keepTurnning = false;
			}
		}
		else
		{
			cout << (int)((robot->getYaw() + 2* M_PI) * 180 / M_PI)  <<  "  "  <<  destWayPointAngl << endl;

			if ((((int)((robot->getYaw() + 2* M_PI) * 180 / M_PI) <= destWayPointAngl +5)) &&
				  ((int)((robot->getYaw() + 2* M_PI) * 180 / M_PI)+5 >= destWayPointAngl))
			{
					keepTurnning = false;
			}
		}
	}
	robot->setRobotSpeed(0.0,0.0);
	robot->robotPositionYaw = destWayPointAngl;
}
