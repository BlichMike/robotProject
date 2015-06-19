//*************************************************************************************/
/*                                                                                    */
/*                          C l a s s  : G o I n P l a c e                            */
/*                          ------------------------------                            */
/*                                                                                    */
/* Description: A class which handles the robot's go in place behavior                */
/*                                                                                    */
/**************************************************************************************/
/*                                                                                    */
/* Methods: startCondition - An overriden method that checks if the go in place       */
/*                           start condition was activated (returns true if so)       */
/*                                                                                    */
/*          stopCondition  - An overriden method that checks if the go in place       */
/*                           stop condition was activated (returns true if so)        */
/*                                                                                    */
/*          action         - An overriden method that controls the go in place action */
/*                           of the current behavior                                  */
/*                                                                                    */
/**************************************************************************************/
#ifndef GOINPLACE_H_
#define GOINPLACE_H_

#include "Robot.h"
#include "Behaviors.h"

using namespace std;

class GoInPlace: public Behaviors
{
	public:

		GoInPlace(Robot* robot);

		bool startCondition();

		bool stopCondition();

		void action();
};

#endif /* GOINPLACE_H_ */
