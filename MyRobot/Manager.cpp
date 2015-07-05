#include "Manager.h"
#include "GoForward.h"
#include "GoRight.h"
#include "GoLeft.h"
#include "GoInPlace.h"

#include "ConfigurationManager.h"
#include <queue>
#include "Node.h"
#include "Astar.h"

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

	localizationManager = new LocalizationManager(robot->robotPositionX,robot->robotPositionY);
}

//A method that controls the robot performance
void Manager::Run()
{
	float deltaCoordinateX, deltaCoordinateY, deltaCoordinateYaw;
	int countSlamExecutions;

	countSlamExecutions = 0;
	currentBehavior     = behavior[0];


	//*********************************

	/*Node *n= NULL;
	// need to be 0
	float startx = ConfigurationManager().getStartLocationX();
	// need to be 0
	float starty = ConfigurationManager().getStartLocationY();
	// need to be the end goal
	float endx = ConfigurationManager().getGoalX();
	// need to be the end goal
	float endy= ConfigurationManager().getGoalY();
	//Set current position
	Node startPosition = Node(*n,startx,starty,0);
	//Set current position
	Node endPosition = Node(*n,endx,endy,0);

	queue<Node> q = Astar().PathPlanner(startPosition,endPosition);
	*/
	//*********************************

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

				localizationManager->particlesUpdate(deltaCoordinateX, deltaCoordinateY, deltaCoordinateYaw, laserScan, LASER_READ);
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
	delete localizationManager;
}
