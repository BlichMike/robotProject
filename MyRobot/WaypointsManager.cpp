/*
 * WaypointsManager.cpp
 *
 *  Created on: Jul 19, 2015
 *      Author: colman
 */

#include "WaypointsManager.h"

namespace std {

WaypointsManager::WaypointsManager() {
	// TODO Auto-generated constructor stub

}

vector<Node*> WaypointsManager::generateWayPoints(Node * startPoint,Node * endPoint)
{
	//        90
	//    135    45
	// 180          0
	//    225    315
	//       270

	Astar * star = new Astar();
	vector<Node*> path = star->PathPlanner(startPoint,endPoint);
	int pathSize = path.size();
	vector<Node*> resultWaypoints;

	for (int index=0; index < pathSize - 1; index++)
	{
		int engle = 0;
		int pointX1 = resultWaypoints[index]->getxPos();
		int pointY1 = resultWaypoints[index]->getyPos();
		int pointX2 = resultWaypoints[index+1]->getxPos();
		int pointY2 = resultWaypoints[index+1]->getyPos();

		// Check if they have the same horizontal
		if (pointX1== pointX2)
		{
			// Check if up
			if(pointY2 > pointY1)
			{
				engle = 90;
			}
			else
			{
				engle = 270;
			}
		}
		// Check if the point is righter
		if (pointX2 > pointX1)
		{
			// Check if upper
			if (pointY2 > pointY1)
			{
				engle = 45;
			}
			else
			{
				engle = 315;
			}
		}
		// Check if lefter
		if (pointX2 < pointX1)
		{
			// Check if upper
			if (pointY2 < pointY1)
			{
				engle = 135;
			}
			else
			{
				engle = 225;
			}
		}

		// Behavior move to engle until point 2


	}
	return resultWaypoints;
}

WaypointsManager::~WaypointsManager()
{
	// TODO Auto-generated destructor stub
}

} /* namespace std */
