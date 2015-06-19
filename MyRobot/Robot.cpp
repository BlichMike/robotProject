#include "Robot.h"

//C'Tor
Robot::Robot(char* ip,int port)
{
	playerClient  = new PlayerClient(ip,port);
	positionProxy = new Position2dProxy(playerClient);
	laserProxy    = new LaserProxy(playerClient);

	robotPositionX    = 0.0;
	robotPositionY    = 0.0;
	robotPositionYaw  = 0.0;

	positionProxy->SetMotorEnable(true);
}

//A method which refreshe's the laser scan (read)
void Robot::refreshLaserScan()
{
	playerClient->Read();
}

//A method which converts a given laser degree to a parallel laser index
int Robot::convertDegToIdx(int degree)
{
	return (degree*3);
}

//A method which converts a given laser index to a parallel laser degree
int Robot::convertIdxToDeg(int index)
{
	return (index/3);
}

/*************************************/
/*         Setters & Getters         */
/*************************************/
//A method which set's the robot's speed
void Robot::setRobotSpeed(double speed, double angle)
{
	positionProxy->SetSpeed(speed,angle);
}

//A method which set's & get's the robot's deltas
void Robot::getRobotDeltas(float &deltaCoordinateX,float &deltaCoordinateY,float &deltaCoordinateYaw)
{
	float xPosition   = positionProxy->GetXPos();
	float yPosition   = positionProxy->GetYPos();
	float yawPosition = positionProxy->GetYaw();

	deltaCoordinateX   = xPosition   - robotPositionX;
	deltaCoordinateY   = yPosition   - robotPositionY;
	deltaCoordinateYaw = yawPosition - robotPositionYaw;

	robotPositionX   = xPosition;
	robotPositionY   = yPosition;
	robotPositionYaw = yawPosition;
}

//A method which get's the laser scan at a specific index
float Robot::getLaserByIdx(int laserIdx)
{
	if (laserIdx > 655 || laserIdx < 0)
	{
		return -1;
	}

	return (*laserProxy)[laserIdx];
}

