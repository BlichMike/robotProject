/****************************************************************************************/
/*                                                                                      */
/*                            C l a s s  : B e h a v i o r s                            */
/*                            ------------------------------                            */
/*                                                                                      */
/* Description: A class which handles the robot's behaviors system                      */
/*              (Go forward, Go left, Go right, Go in place)                            */
/*                                                                                      */
/****************************************************************************************/
/*                                                                                      */
/* Methods: startCondition - A virtual method to be overriden which checks if the       */
/*                           start condition was activated (returns true if so)         */
/*                                                                                      */
/*          stopCondition  - A virtual method to be overriden which checks if the       */
/*                           stop condition was activated (returns true if so)          */
/*                                                                                      */
/*          action         - A virtual method to be overriden which controls the action */
/*                           of the current behavior                                    */
/*                                                                                      */
/*          addNext        - A method to add a behavior to the behavior's linked list   */
/*																					    */
/*          getNext        - A method to get the next behavior from the behavior's      */
/*                           linked list                                                */
/*                                                                                      */
/****************************************************************************************/
#ifndef BEHAVIORS_H_
#define BEHAVIORS_H_

#include "Robot.h"

using namespace std;

class Behaviors
{
	int _numNext;
	Behaviors** _next;

protected:
	Robot * robot;

public:

	Behaviors(Robot * robot);

	virtual bool startCondition() = 0;

	virtual bool stopCondition() = 0;

	virtual void action() = 0;

	bool addNext(Behaviors * next);

	Behaviors * getNext();

	virtual ~Behaviors();
};

#endif /* BEHAVIORS_H_ */
