#ifndef MANAGER_H_
#define MANAGER_H_

#include "Robot.h"
#include "Behaviors.h"
#include "LocalizationManager.h"

#define LASER_READ 655

using namespace std;

class Manager
{
	Robot * robot;
	Behaviors * behavior[4];
	Behaviors * currentBehavior;
	LocalizationManager * localizationManager;
	float laserScan[LASER_READ];

	public:
		Manager(Robot* robot);

		void Run();

		~Manager();
};

#endif /* MANAGER_H_ */
