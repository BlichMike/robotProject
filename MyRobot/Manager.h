//*********************************************************************************/
/*                                                                                */
/*                            C l a s s  : M a n a g e r                          */
/*                            --------------------------                          */
/*                                                                                */
/* Description: A class which handles all the robot's control system              */
/*                                                                                */
/**********************************************************************************/
/*                                                                                */
/* Methods: Run - A method that controls the robot performance                    */
/*                                                                                */
/**********************************************************************************/
#ifndef MANAGER_H_
#define MANAGER_H_

#include "Robot.h"
#include "Behaviors.h"
#include "SlamAlgorithm.h"

#define LASER_READ 655

using namespace std;

class Manager
{
	Robot * robot;
	Behaviors * behavior[4];
	Behaviors * currentBehavior;
	SlamAlgorithm * slamAlgorithm;
	float laserScan[LASER_READ];

	public:
		Manager(Robot* robot);

		void Run();

		~Manager();
};

#endif /* MANAGER_H_ */
