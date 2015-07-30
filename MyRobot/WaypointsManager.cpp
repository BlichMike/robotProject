
#include "WaypointsManager.h"


namespace std {

WaypointsManager::WaypointsManager() {
	// TODO Auto-generated constructor stub

}

vector<waypoint*> WaypointsManager::generateWayPoints(Node * startPoint,Node * endPoint)
{
	//        90
	//    135    45
	// 180          0
	//    225    315
	//       270

	Astar * star = new Astar();
	vector<Node*> path = star->PathPlanner(startPoint,endPoint);
	int pathSize = path.size();
	Map * m = new Map();
	vector<waypoint*> resultWaypoints;

	for (int index=0; index < pathSize - 1; index++)
	{
		int engle = 0;
		int pointX1 = path[index]->getxPos();
		int pointY1 = path[index]->getyPos();
		int pointX2 = path[index+1]->getxPos();
		int pointY2 = path[index+1]->getyPos();

		// Check if they have the same horizontal
		if (pointY1== pointY2)
		{
			// Check if up
			if(pointX2 > pointX1)
			{
				engle = 0;
			}
			else
			{
				engle = 180;
			}
		}else if(pointX1== pointX2)
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
			}else if (pointX2 > pointX1)
				{// Check if the point is righter

				// Check if upper
				if (pointY2 > pointY1)
				{
					engle = 45;
				}
				else
				{
					engle = 315;
				}
				}else if (pointX2 < pointX1)
					{// Check if lefter
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
		waypoint * newWaypoint = new waypoint(path[index+1]->getxPos(),path[index+1]->getyPos(), engle);
		resultWaypoints.push_back(newWaypoint);
	}
	return resultWaypoints;
}

WaypointsManager::~WaypointsManager()
{
	// TODO Auto-generated destructor stub
}

} /* namespace std */
