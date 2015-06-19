//**********************************************************************************/
/*                                                                                 */
/*                            C l a s s  : G o R i g h t                           */
/*                            --------------------------                           */
/*                                                                                 */
/* Description: A class which handles the robot's go right behavior                */
/*                                                                                 */
/***********************************************************************************/
/*                                                                                 */
/* Methods: startCondition - An overriden method that checks if the go right       */
/*                           start condition was activated (returns true if so)    */
/*                                                                                 */
/*          stopCondition  - An overriden method that checks if the go right       */
/*                           stop condition was activated (returns true if so)     */
/*                                                                                 */
/*          action         - An overriden method that controls the go right action */
/*                           of the current behavior                               */
/*                                                                                 */
/***********************************************************************************/
#ifndef GORIGHT_H_
#define GORIGHT_H_

#include "Robot.h"
#include "Behaviors.h"
using namespace std;

class GoRight: public Behaviors
{
	public:
		GoRight(Robot* robot);

		bool startCondition();

		bool stopCondition();

		void action();
};

#endif /* GORIGHT_H_ */
