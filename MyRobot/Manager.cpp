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
	int deltaCoordinateX, deltaCoordinateY;
	double deltaCoordinateYaw;
	int countSlamExecutions;
	WaypointsManager * waypointsMgr = new WaypointsManager();

	countSlamExecutions = 0;
	currentBehavior     = behavior[1];



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


	for (int i=0; i < 20; i++)
	{
		robot->setOdometry(startx,starty,configFile->getStartLocationYaw());
		robot->refreshLaserScan();
	}

	for (int i = 0; i < waypoints.size(); i++)
	{
		cout << waypoints[i]->getxPos() << "," << waypoints[i]->getyPos() << endl;
	}

	int wpSize = waypoints.size();
	int index = 0;
	// Dont stop tring ever !
	while(true)
	{
		Particle * bestParticle = NULL;

		robot->refreshLaserScan();
		if (index < wpSize)
		{
			robot->CurrDestY = waypoints[index]->getyPos();
			robot->currDestX = waypoints[index]->getxPos();
			robot->curDestAngl = waypoints[index]->getEngle();
		}

		// check if need to move
		if (currentBehavior->startCondition())
		{
			// move
			currentBehavior->action();


			// move until you get to the end of behavior
			while (!currentBehavior->stopCondition())
			{
				// do the slam
				//currentBehavior = currentBehavior->getNext();
				if (countSlamExecutions % 10 == 0)
				{
					robot->getRobotDeltas(deltaCoordinateX, deltaCoordinateY, deltaCoordinateYaw);
					for (int i = 0; i < LASER_READ; i++)
					{
						laserScan[i] = robot->getLaserByIdx(i);
					}
				//	localizationManager->particlesUpdate(deltaCoordinateX, deltaCoordinateY, deltaCoordinateYaw, laserScan, LASER_READ);
				}
				//Particle * bestParticle = localizationManager->getParticleWithMaxBelief();
			//	bestParticle = localizationManager->getParticleWithMaxBelief();
			}
			//cout << "x="   << bestParticle->particleCoordinateX << endl;
		//	cout << "Y="   << bestParticle->particleCoordinateY << endl;
		//	cout << "YAW=" << bestParticle->particleCoordinateYaw * 180 / M_PI << endl;
			// Change the bihavior

			index++;
		}
		currentBehavior = currentBehavior->getNext();
		cout << " ********************* "  << endl;
		//robot->setOdometry(bestParticle->particleCoordinateX,
			//					   bestParticle->particleCoordinateY,
			//	    			   bestParticle->particleCoordinateYaw);

	}

	//*****************************************************************


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
