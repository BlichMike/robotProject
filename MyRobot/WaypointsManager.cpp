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
	Astar * star = new Astar();
	vector<Node*> path = star->PathPlanner(startPoint,endPoint);
	int pathSize = path.size();
	vector<Node*> resultWaypoints;


	for (int i=1; i < pathSize - 1; i++)
	{
		// set waypoints here
	}
	return resultWaypoints;
}

WaypointsManager::~WaypointsManager() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
