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
