#include <iostream>
#include "Robot.h"
#include "Manager.h"
#include "ConfigurationManager.h"
#include <string>
using namespace std;

int main()
{
	cout<<"System is booting up..."<<endl;

	cout<<"Enter the parameters file name\n";
	string fileName="parameters.txt";
	//cin>>fileName;
	ConfigurationManager *configFile;
	configFile = ConfigurationManager::getInstance();
	configFile->readConfigFile(fileName);
	/* Connection for Player/Stage */

	Robot robot((char*)"localhost",6665);

	/* Connection for live test */
	//Robot robot((char*)"10.10.245.62",6665);

	Manager manager(&robot);
	manager.Run();

	cout<<"System is shutting down..."<<endl;

	return 0;
}
