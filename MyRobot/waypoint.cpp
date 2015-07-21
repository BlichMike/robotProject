/*
 * waypoint.cpp
 *
 *  Created on: Jul 21, 2015
 *      Author: colman
 */

#include "waypoint.h"

waypoint::waypoint(int CurrXPosition, int CurrYPosition,int engle)
{
	this->engle = engle;
	this->xPos = CurrXPosition;
	this->yPos = CurrYPosition;
}
