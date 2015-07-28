#include "Behaviors.h"

//C'Tor
Behaviors::Behaviors(Robot * robot):robot(robot), _numNext(0),_next(NULL){}

// add behaviors to list
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

// get next nehavior from the list
Behaviors * Behaviors::getNext()
{
	return _next[0];
}

//D'Tor
Behaviors::~Behaviors()
{
	delete[] _next;
}
