//*********************************************************************************/
/*                                                                                */
/*                            C l a s s  : G o L e f t                            */
/*                            ------------------------                            */
/*                                                                                */
/* Description: A class which handles the robot's go left behavior                */
/*                                                                                */
/**********************************************************************************/
/*                                                                                */
/* Methods: startCondition - An overriden method that checks if the go left       */
/*                           start condition was activated (returns true if so)   */
/*                                                                                */
/*          stopCondition  - An overriden method that checks if the go left       */
/*                           stop condition was activated (returns true if so)    */
/*                                                                                */
/*          action         - An overriden method that controls the go left action */
/*                           of the current behavior                              */
/*                                                                                */
/**********************************************************************************/
#ifndef GOLEFT_H_
#define GOLEFT_H_

#include "Robot.h"
#include "Behaviors.h"
using namespace std;

//Class which controls the TurnLeft behavior
class GoLeft: public Behaviors
{
	public:
		GoLeft(Robot* robot);

		bool startCondition();

		bool stopCondition();

		void action();
};

#endif /* GOLEFT_H_ */
