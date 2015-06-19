#include "GoForward.h"

//C'Tor
GoForward::GoForward(Robot * robot):Behaviors(robot) {}

//An overriden method that checks if the go forward start condition was activated (returns true if so)
bool GoForward::startCondition()
{
	return true;
}

//An overriden method that checks if the go forward stop condition was activated (returns true if so)
bool GoForward::stopCondition()
{
	int wallAheadCount 	= 0;
	int rightWallCount	= 0;
	int leftWallCount 	= 0;

	for (int i=robot->convertDegToIdx(-20) ; i<(robot->convertDegToIdx(20)) ; i = i+3)
	{
		if((robot->getLaserByIdx(LASERREAD+i) < SAFE_RANGE))
		{
			wallAheadCount++;

			for (int j=robot->convertDegToIdx(-10) ; j<(robot->convertDegToIdx(10)) ; j+= 3)
			{
				if ((robot->getLaserByIdx((robot->convertDegToIdx(150)) + j) < WALL_RANGE) || (robot->getLaserByIdx((robot->convertDegToIdx(210)) + j) < WALL_RANGE))
					leftWallCount++;

				if ((robot->getLaserByIdx((robot->convertDegToIdx(90)) + j) < WALL_RANGE) || (robot->getLaserByIdx((robot->convertDegToIdx(30)) + j) < WALL_RANGE))
					rightWallCount++;

				if (rightWallCount == 10)
				{
					robot->setRobotSpeed(0.0,1.0);
					cout<<"SYSTEM: Stop condition was triggered >> Wall on the right!"<<endl;
					return true;
				}

				if (leftWallCount == 10)
				{
					robot->setRobotSpeed(0.0,-1.0);
					cout<<"SYSTEM: Stop condition was triggered >> Wall on the left!"<<endl;
					return true;
				}
			}

			if (wallAheadCount == 20)
			{
				robot->setRobotSpeed(0.0,1.0);
				cout<<"SYSTEM: Stop condition was triggered >> Wall ahead!!!"<<endl;
				return true;
			}
		}
	}
	return false;
}

//An overriden method that controls the go forward action of the current behavior
void GoForward::action()
{
	robot->setRobotSpeed(0.3,0.0);
}
