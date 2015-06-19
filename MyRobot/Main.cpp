//============================================================================
// Name        : Main.cpp
// Authors     : Erez Barash, Or Moushkatel, Shelly Yael & Elinor Vaknin
// Version     :
//============================================================================

#include <iostream>
#include "Robot.h"
#include "Manager.h"
using namespace std;

int main()
{
	cout<<"System is booting up..."<<endl;

	/* Connection for Player/Stage */
	Robot robot((char*)"localhost",6665);

	/* Connection for live test */
	//Robot robot((char*)"10.10.245.62",6665);

	Manager manager(&robot);
	manager.Run();

	cout<<"System is shutting down..."<<endl;

	return 0;
	//asdfsd
}
