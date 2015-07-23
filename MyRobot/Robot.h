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
	double robotPositionX, robotPositionY, robotPositionYaw;
	double currDestX, CurrDestY, curDestAngl;

	Robot(char* ip,int port);

	void setOdometry(double x, double y, double yaw);

	void refreshLaserScan();

	Position2dProxy getPosition();

	int convertDegToIdx(int degree);

	double getYaw(){return positionProxy->GetYaw();}

	double getXPos(){return positionProxy->GetXPos();}

	double getYPos(){return positionProxy->GetYPos();}

	int convertIdxToDeg(int index);

	void setRobotSpeed(double speed, double angle);

	void getRobotDeltas(double &deltaCoordinateX,double &deltaCoordinateY,double &deltaCoordinateYaw);

	double getLaserByIdx(int laserIdx);
};

#endif /* ROBOT_H_ */
