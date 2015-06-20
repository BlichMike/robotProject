#include "Robot.h"
#include "ConfigurationManager.h"

//C'Tor
Robot::Robot(char* ip,int port)
{
	ConfigurationManager *configFile;
	configFile = ConfigurationManager::getInstance();
	playerClient  = new PlayerClient(ip,port);
	positionProxy = new Position2dProxy(playerClient);
	laserProxy    = new LaserProxy(playerClient);

	robotPositionX    = configFile->getStartLocationX();
	robotPositionY    = configFile->getStartLocationY();
	robotPositionYaw  = configFile->getStartLocationYaw();

	positionProxy->SetMotorEnable(true);
}

//refreshes the laser scan (read)
void Robot::refreshLaserScan()
{
	playerClient->Read();
}

//A method which converts a given laser degree to laser index
int Robot::convertDegToIdx(int degree)
{
	return (degree*3);
}

//converts a given laser index to laser degree
int Robot::convertIdxToDeg(int index)
{
	return (index/3);
}

// Getters and Setters
// Sets the robot's speed
void Robot::setRobotSpeed(double speed, double angle)
{
	positionProxy->SetSpeed(speed,angle);
}

// Sets & gets the robots deltas
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

// Gets the laser scan at a specific index
float Robot::getLaserByIdx(int laserIdx)
{
	if (laserIdx > 655 || laserIdx < 0)
	{
		return -1;
	}

	return (*laserProxy)[laserIdx];
}

