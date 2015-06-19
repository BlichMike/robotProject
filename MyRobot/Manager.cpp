#include "Manager.h"
#include "GoForward.h"
#include "GoRight.h"
#include "GoLeft.h"
#include "GoInPlace.h"

//C'Tor
Manager::Manager(Robot* robot) :robot(robot)
{
	// Behavior Creation
	behavior[0] = new GoForward(robot);
	behavior[1] = new GoRight(robot);
	behavior[2] = new GoLeft(robot);
	behavior[3] = new GoInPlace(robot);

	// Behavior Connection
	behavior[0]->addNext(behavior[1]);
	behavior[0]->addNext(behavior[2]);
	behavior[0]->addNext(behavior[3]);
	behavior[1]->addNext(behavior[0]);
	behavior[2]->addNext(behavior[0]);
	behavior[3]->addNext(behavior[0]);

	slamAlgorithm = new SlamAlgorithm(robot->robotPositionX,robot->robotPositionY);
}

//A method that controls the robot performance
void Manager::Run()
{
	float deltaCoordinateX, deltaCoordinateY, deltaCoordinateYaw;
	int countSlamExecutions;

	countSlamExecutions = 0;
	currentBehavior     = behavior[0];

	robot->refreshLaserScan();

	if (currentBehavior->startCondition() == false)
		return;

	while (true)
	{
		robot->refreshLaserScan();

		while ((currentBehavior->stopCondition()) == false)
		{
			robot->refreshLaserScan();

			if (countSlamExecutions % 10 == 0)
			{
				robot->getRobotDeltas(deltaCoordinateX, deltaCoordinateY, deltaCoordinateYaw);

				for (int i = 0; i < LASER_READ; i++)
					laserScan[i] = robot->getLaserByIdx(i);

				robot->setRobotSpeed(0.0,0.0);

				slamAlgorithm->particlesUpdate(deltaCoordinateX, deltaCoordinateY, deltaCoordinateYaw, laserScan, LASER_READ);
			}

			countSlamExecutions++;

			currentBehavior->action();
		}

		currentBehavior = currentBehavior->getNext();
	}
}

//D'Tor
Manager::~Manager()
{
	int i;

	for (i = 0; i < 4; i++)
		delete behavior[i];

	delete robot;
	delete currentBehavior;
	delete laserScan;
	delete slamAlgorithm;
}
