#ifndef WAYPOINTSMANAGER_H_
#define WAYPOINTSMANAGER_H_
#include "Node.h"
#include "Astar.h"
#include <vector>
#include "waypoint.h"

namespace std {

class WaypointsManager {
public:
	WaypointsManager();
	vector<waypoint*> generateWayPoints(Node * startPoint,Node * endPoint);
	virtual ~WaypointsManager();
};

} /* namespace std */

#endif /* WAYPOINTSMANAGER_H_ */
