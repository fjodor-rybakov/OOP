// CarCreator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CController.h"
#include "iostream"
#include "string"

using namespace std;

int main()
{
	CCar audi;
	CController controllerAudi(audi);
	cout << "Available command for car control" << endl;
	cout << "Info" << endl;
	cout << "EngineOn" << endl;
	cout << "EngineOff" << endl;
	cout << "SetGear" << endl;
	cout << "SetSpeed" << endl;
	cout << "exit" << endl;
	int gear = 0, speed = 0;
	string command;
	do
	{
		getline(cin, command);
		if (command == "Info")
		{
			controllerAudi.Info();
		}
		else if (command == "EngineOn")
		{
			controllerAudi.EngineOn();
		}
		else if (command == "EngineOff")
		{
			controllerAudi.EngineOff();
		}
		else if (command == "SetGear")
		{
			cout << "Enter gear" << endl;
			cin >> gear;
			controllerAudi.SetGear(gear);
		}
		else if (command == "SetSpeed")
		{
			cout << "Enter speed" << endl;
			cin >> speed;
			controllerAudi.SetSpeed(speed);
		}
	} while (command != "exit");

    return 0;
}

