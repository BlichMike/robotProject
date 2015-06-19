#include "GoInPlace.h"

//C'Tor
GoInPlace::GoInPlace(Robot * robot):Behaviors(robot) {}

//An overriden method that checks if the go in place start condition was activated (returns true if so)
bool GoInPlace::startCondition()
{
	return true;
}

//An overriden method that checks if the go in place stop condition was activated (returns true if so)
bool GoInPlace::stopCondition()
{
	int freeWayAheadCount = 0;

	for (int i=robot->convertDegToIdx(-30) ; i<(robot->convertDegToIdx(30)) ; i += 3)
	{
		if(robot->getLaserByIdx(LASERREAD+i) > SAFE_RANGE)
		{
			freeWayAheadCount++;

			if (freeWayAheadCount == 40)
			{
				cout<<"SYSTEM: Go in place stop condition was triggered"<<endl;
				return true;
			}
		}
	}
	return false;
}

//An overriden method that controls the go in place action of the current behavior
void GoInPlace::action()
{
	robot->setRobotSpeed(0.0,1.0);
}
