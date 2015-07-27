#include "GoInPlace.h"

//C'Tor
GoInPlace::GoInPlace(Robot * robot):Behaviors(robot) {}

// turn in place
bool GoInPlace::startCondition()
{
	bool keepTurnning = true;
	int destWayPointAngl = robot->curDestAngl;
	robot->refreshLaserScan();

	if (robot->getYaw() > 0 )
	{
		//cout << (int)(robot->getYaw() * 180 / M_PI)  <<  "  "  <<  destWayPointAngl << endl;
		if (((int)(robot->getYaw()*180 / M_PI) <= destWayPointAngl + 5) &&
		     ((int)(robot->getYaw()*180 / M_PI) +5 >= destWayPointAngl))
		{
			keepTurnning = false;
		}
	}
	else
	{
		//cout << (int)((robot->getYaw() + 2* M_PI) * 180 / M_PI)  <<  "  "  <<  destWayPointAngl << endl;
			if ((((int)((robot->getYaw() + 2* M_PI) * 180 / M_PI) <= destWayPointAngl +5)) &&
			  ((int)((robot->getYaw() + 2* M_PI) * 180 / M_PI)+5 >= destWayPointAngl))
		{
			keepTurnning = false;
		}
	}

	// return true only if u need to set new angel
	return keepTurnning;
}

// stop turn in place
bool GoInPlace::stopCondition()
{
	int destWayPointAngl = robot->curDestAngl;
	bool stopTurnning = false;
	robot->refreshLaserScan();

	if (robot->getYaw() > 0 )
	{
		cout << (int)(robot->getYaw() * 180 / M_PI)  <<  "  "  <<  destWayPointAngl << endl;
		if (((int)(robot->getYaw()*180 / M_PI) <= destWayPointAngl + 5) &&
		     ((int)(robot->getYaw()*180 / M_PI) +5 >= destWayPointAngl))
		{
			stopTurnning = true;
		}
	}
	else
	{
		cout << (int)((robot->getYaw() + 2* M_PI) * 180 / M_PI)  <<  "  "  <<  destWayPointAngl << endl;
		if ((((int)((robot->getYaw() + 2* M_PI) * 180 / M_PI) <= destWayPointAngl +5)) &&
		     ((int)((robot->getYaw() + 2* M_PI) * 180 / M_PI)+5 >= destWayPointAngl))
		{
			stopTurnning = true;
		}
	}

	if (stopTurnning)
	{
		robot->setRobotSpeed(0.0,0.0);
		robot->robotPositionYaw = destWayPointAngl;
	}

	return stopTurnning;
}

// action
void GoInPlace::action()
{
	robot->setRobotSpeed(0.0,0.3);
}
