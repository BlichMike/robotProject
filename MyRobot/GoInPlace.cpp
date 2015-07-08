#include "GoInPlace.h"

//C'Tor
GoInPlace::GoInPlace(Robot * robot):Behaviors(robot) {}

// turn in place
bool GoInPlace::startCondition()
{
	return true;
}

// stop turn in place
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

// action
void GoInPlace::action()
{
	robot->setRobotSpeed(0.0,1.0);
}
