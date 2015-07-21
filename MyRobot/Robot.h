/****************************************************************************************/
/*                                                                                      */
/*                               C l a s s  :  R o b o t                                */
/*                               -----------------------                                */
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
	float currDestX, CurrDestY, curDestAngl;

	Robot(char* ip,int port);

	void refreshLaserScan();

	Position2dProxy getPosition();

	int convertDegToIdx(int degree);

	int getYaw(){return positionProxy->GetYaw();}

	int convertIdxToDeg(int index);

	void setRobotSpeed(double speed, double angle);

	void getRobotDeltas(float &deltaCoordinateX,float &deltaCoordinateY,float &deltaCoordinateYaw);

	float getLaserByIdx(int laserIdx);
};

#endif /* ROBOT_H_ */
