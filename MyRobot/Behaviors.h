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
