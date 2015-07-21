/*
 * waypoint.h
 *
 *  Created on: Jul 21, 2015
 *      Author: colman
 */

#ifndef WAYPOINT_H_
#define WAYPOINT_H_

class waypoint {

	int xPos;
	int yPos;
	int engle;

public:
	waypoint(int CurrXPosition, int CurrYPosition,int engle);
	int getxPos() {return xPos;}
	int getyPos() {return yPos;}
	int getEngle() {return engle;}
};

#endif /* WAYPOINT_H_ */
