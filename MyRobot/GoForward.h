//************************************************************************************/
/*                                                                                   */
/*                           C l a s s  : G o F o r w a rd                           */
/*                           -----------------------------                           */
/*                                                                                   */
/* Description: A class which handles the robot's go forward behavior                */
/*                                                                                   */
/*************************************************************************************/
/*                                                                                   */
/* Methods: startCondition - An overriden method that checks if the go forward       */
/*                           start condition was activated (returns true if so)      */
/*                                                                                   */
/*          stopCondition  - An overriden method that checks if the go forward       */
/*                           stop condition was activated (returns true if so)       */
/*                                                                                   */
/*          action         - An overriden method that controls the go forward action */
/*                           of the current behavior                                 */
/*                                                                                   */
/*************************************************************************************/
#ifndef GOFORWARD_H_
#define GOFORWARD_H_

#include "Robot.h"
#include "Behaviors.h"

using namespace std;

//Class which controls the GoForward behavior
class GoForward: public Behaviors
{
	public:
		GoForward(Robot* robot);

		bool startCondition();

		bool stopCondition();

		void action();
};
#endif /* GOFORWARD_H_ */
