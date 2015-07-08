#include "GoRight.h"

//C'Tor
GoRight::GoRight(Robot * robot):Behaviors(robot) {}

// true
bool GoRight::startCondition()
{
	int count = 0;
	int read  = (robot->convertDegToIdx(80));

	for (int i=robot->convertDegToIdx(-10) ; i<(robot->convertDegToIdx(10)) ; i++)
	{
		if(robot->getLaserByIdx(read+i) > SAFE_RANGE)
		{
			count++;

			if (count == 10)
			{
				cout<<"SYSTEM: Go right start condition was triggered"<<endl;
				return true;
			}
		}
	}
	return false;
}


// stop going right
bool GoRight::stopCondition()
{
	int freeWayAheadCount = 0;

	for (int i=robot->convertDegToIdx(-15) ; i<(robot->convertDegToIdx(15)) ; i +=3)
	{
		if(robot->getLaserByIdx(LASERREAD+i) > SAFE_RANGE)
		{
			freeWayAheadCount++;

			if (freeWayAheadCount == 30)
			{
				cout<<"SYSTEM: Go right stop condition triggered"<<endl;
				return true;
			}
		}
	}
	return false;
}

// action
void GoRight::action()
{
	robot->setRobotSpeed(0.0,-1.0);
}
