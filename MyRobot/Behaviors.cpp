#include "Behaviors.h"

//C'Tor
Behaviors::Behaviors(Robot * robot):robot(robot), _numNext(0),_next(NULL){}

//A method to add a behavior to the behavior's linked list
bool Behaviors::addNext(Behaviors * next)
{
	int i;
	Behaviors** tempBehaviorList;

	tempBehaviorList = new Behaviors * [_numNext+1];

	if (!tempBehaviorList)
		return false;

	for (i=0; i<_numNext; i++)
	{
		tempBehaviorList[i] = _next[i];
	}

	_numNext++;
	tempBehaviorList[i] = next;

	delete[] _next;
	_next = tempBehaviorList;

	return true;
}

//A method to get the next behavior from the behavior's linked list
Behaviors * Behaviors::getNext()
{
	for (int i=0 ; i<_numNext ; i++)
	{
		if (_next[i]->startCondition())
			return _next[i];
	}

	return NULL;
}

//D'Tor
Behaviors::~Behaviors()
{
	delete[] _next;
}
