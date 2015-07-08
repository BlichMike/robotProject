//*********************************************************************************/
/*                                                                                */
/*                            C l a s s  : G o L e f t                            */
/*                            ------------------------                            */
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
