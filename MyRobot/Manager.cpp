#include "Manager.h"
#include "GoForward.h"
#include "GoInPlace.h"

#include "ConfigurationManager.h"
#include <queue>
#include "Node.h"
#include "WaypointsManager.h"
#include "waypoint.h"


//C'Tor
Manager::Manager(Robot* robot) :robot(robot)
{
	// Behavior Creation
	behavior[0] = new GoForward(robot);

	behavior[1] = new GoInPlace(robot);

	// Behavior Connection
	behavior[0]->addNext(behavior[1]);

	behavior[1]->addNext(behavior[0]);
	localizationManager = new LocalizationManager(robot->robotPositionX,robot->robotPositionY);
}

// function the init the robot manager
void Manager::Run()
{
	float deltaCoordinateX, deltaCoordinateY, deltaCoordinateYaw;
	int countSlamExecutions;
	WaypointsManager * waypointsMgr = new WaypointsManager();

	countSlamExecutions = 0;
	currentBehavior     = behavior[0];


	//*********************************
	ConfigurationManager *configFile;
	configFile = ConfigurationManager::getInstance();
	Node* n = 0;
	// need to be 0
	int startx = configFile->getStartLocationX();
	// need to be 0
	int starty = configFile->getStartLocationY();
	// need to be the end goal
	int endx = configFile->getGoalX();
	// need to be the end goal
	int endy= configFile->getGoalY();
	//Set current position
	Node * startPosition = new Node(*n,startx,starty,0);
	startPosition->updatePriority(endx,endy);
	//Set current position
	Node * endPosition = new Node(*n,endx,endy,0);
	vector<waypoint*> waypoints = waypointsMgr->generateWayPoints(startPosition, endPosition);

	//*********************************

	//robot->refreshLaserScan();
	for (int i = 0; i < waypoints.size(); i++)
	{
		robot->refreshLaserScan();
		robot->CurrDestY = waypoints[i]->getyPos();
		robot->currDestX = waypoints[i]->getxPos();
		robot->curDestAngl = waypoints[i]->getEngle();
		currentBehavior->action();
		currentBehavior = currentBehavior->getNext();
		localizationManager->particlesUpdate(deltaCoordinateX, deltaCoordinateY, deltaCoordinateYaw, laserScan, LASER_READ);
	}
	/*while (true)
	{
		robot->setRobotSpeed(0.6,0.0);
		//robot->refreshLaserScan();

		while ((currentBehavior->stopCondition()) == false)
		{
			//robot->refreshLaserScan();

			if (countSlamExecutions % 10 == 0)
			{
				robot->getRobotDeltas(deltaCoordinateX, deltaCoordinateY, deltaCoordinateYaw);

				for (int i = 0; i < LASER_READ; i++)
					laserScan[i] = robot->getLaserByIdx(i);

				robot->setRobotSpeed(0.6,0.0);

				localizationManager->particlesUpdate(deltaCoordinateX, deltaCoordinateY, deltaCoordinateYaw, laserScan, LASER_READ);
			}

			countSlamExecutions++;

			currentBehavior->action();
		}

		currentBehavior = currentBehavior->getNext();
	}*/
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
