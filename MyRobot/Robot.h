/****************************************************************************************/
/*                                                                                      */
/*                               C l a s s  :  R o b o t                                */
/*                               -----------------------                                */
/*                                                                                      */
/* Description: A class which handles the robot's system (positions, connection & more) */
/*                                                                                      */
/****************************************************************************************/
/*                                                                                      */
/* Methods: refreshLaserScan - A method which refreshe's the laser scan (read)          */
/*                                                                                      */
/*          convertDegToIdx  - A method which converts a given laser degree to a        */
/*                             parallel laser index                                     */
/*                                                                                      */
/*          convertIdxToDeg  - A method which converts a given laser index to a         */
/*                             parallel laser degree                                    */
/*                                                                                      */
/*          setRobotSpeed    - A method which set's the robot's speed                   */
/*																					    */
/*          getRobotDeltas   - A method which set's & get's the robot's deltas          */
/*                                                                                      */
/*          getLaserByIdx    - A method which get's the laser scan at a specific index  */
/*                                                                                      */
/****************************************************************************************/

#ifndef ROBOT_H_
#define ROBOT_H_

#include <libplayerc++/playerc++.h>

using namespace PlayerCc;
using namespace std;

#define SAFE_RANGE 	0.5
#define WALL_RANGE 	0.5
#define LASERREAD	328

class Robot
{
	PlayerClient    * playerClient;
	Position2dProxy * positionProxy;
	LaserProxy      * laserProxy;

public:
	float robotPositionX, robotPositionY, robotPositionYaw;

	Robot(char* ip,int port);

	void refreshLaserScan();

	int convertDegToIdx(int degree);

	int convertIdxToDeg(int index);

	void setRobotSpeed(double speed, double angle);

	void getRobotDeltas(float &deltaCoordinateX,float &deltaCoordinateY,float &deltaCoordinateYaw);

	float getLaserByIdx(int laserIdx);
};

#endif /* ROBOT_H_ */
