/*
 * WaypointsManager.h
 *
 *  Created on: Jul 19, 2015
 *      Author: colman
 */

#ifndef WAYPOINTSMANAGER_H_
#define WAYPOINTSMANAGER_H_
#include "Node.h"
#include "Astar.h"
#include <vector>

namespace std {

class WaypointsManager {
public:
	WaypointsManager();
	vector<Node*> generateWayPoints(Node * startPoint,Node * endPoint);
	virtual ~WaypointsManager();
};

} /* namespace std */

#endif /* WAYPOINTSMANAGER_H_ */
