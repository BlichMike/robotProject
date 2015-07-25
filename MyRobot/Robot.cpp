#include "Robot.h"
#include "ConfigurationManager.h"

//C'Tor
Robot::Robot(char* ip,int port)
{
	ConfigurationManager *configFile;
	configFile = ConfigurationManager::getInstance();

	double mapRes = configFile->getMapResolutionCM();
	robotRealYStartPosition = configFile->getStartLocationY();
	playerClient  = new PlayerClient(ip,port);
	positionProxy = new Position2dProxy(playerClient);
	laserProxy    = new LaserProxy(playerClient);

	robotPositionX    = configFile->getStartLocationX();
	robotPositionY    = configFile->getStartLocationY();
	robotPositionYaw  = configFile->getStartLocationYaw();

	setOdometry(robotPositionX, robotPositionY, robotPositionYaw);

	for (int i=0; i < 15; i ++)
	{
		refreshLaserScan();
	}

	positionProxy->SetMotorEnable(true);

	for (int i=0; i < 15; i ++)
	{
		refreshLaserScan();
	}

}


void Robot::setOdometry(double x, double y, double yaw)
{

	ConfigurationManager *configFile;
	configFile = ConfigurationManager::getInstance();
	double mapRes = configFile->getMapResolutionCM();
	// convert to meteres
	x = x * mapRes / 100;
	y = y * mapRes / 100;
	// Convert to degree
	double w = (yaw > 180)? ((-1) * (360 - yaw)): yaw;
	// convert to radian
	w  = (w * M_PI ) / 180;
	positionProxy->SetOdometry(x, y, w);
	refreshLaserScan();
}

//refreshes the laser scan (read)
void Robot::refreshLaserScan()
{
	playerClient->Read();
	playerClient->Read();
}

// converts a given laser degree to laser index
int Robot::convertDegToIdx(int degree)
{
	return (degree*3);
}

//converts a given laser index to laser degree
int Robot::convertIdxToDeg(int index)
{
	return (index/3);
}

// sets the robot's speed
void Robot::setRobotSpeed(double speed, double angle)
{
	positionProxy->SetSpeed(speed,angle);
}

// sets & gets the robots deltas
void Robot::getRobotDeltas(int &deltaCoordinateX,int &deltaCoordinateY, double &deltaCoordinateYaw)
{
	refreshLaserScan();
	ConfigurationManager *configFile = ConfigurationManager::getInstance();

	float xPosition   = positionProxy->GetXPos() * 100 / configFile->getMapResolutionCM();
	float yPosition   = positionProxy->GetYPos() * 100 / configFile->getMapResolutionCM();
	float yawPosition = positionProxy->GetYaw() * 180 / M_PI ;

	deltaCoordinateX   = xPosition   - robotPositionX;
	deltaCoordinateY   = yPosition   - robotPositionY;
	deltaCoordinateYaw = (yawPosition - robotPositionYaw) * M_PI / 180;

	robotPositionX   = xPosition;
	robotPositionY   = yPosition;
	robotPositionYaw = yawPosition;
}

// sets the laser scan at a specific index
double Robot::getLaserByIdx(int laserIdx)
{
	if (laserIdx > 655 || laserIdx < 0)
	{
		return -1;
	}

	return (*laserProxy)[laserIdx];
}

