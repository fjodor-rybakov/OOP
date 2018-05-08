// VolumetricShape.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CSphere.h"
#include "CParallelepiped.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CCompound.h"
#include "BodyController.h"
#include "string"

using namespace std;

int main()
{
	cout << "Volumetric shape" << endl;
	cout << "Command Sphere - create shpere" << endl;
	cout << "Command Parallelepiped - create parallelepiped" << endl;
	cout << "Command Cone - create cone" << endl;
	cout << "Command Cylinder - create cone" << endl;
	cout << "Command Compound - create cone" << endl;
	cout << "Command Exit - exit from program" << endl;
	BodyController controller;
	string command;
	while (true)
	{
		cin >> command;
		if (command == "Sphere")
		{
			controller.AddSphere();
		}
		else if (command == "Parallelepiped")
		{
			controller.AddParallelepiped();
		}
		else if (command == "Cone")
		{
			controller.AddCone();
		}
		else if (command == "Cylinder")
		{
			controller.AddCylinder();
		}
		else if (command == "Compound")
		{
			controller.AddCompound();
		}
		else if (command == "Exit")
		{
			controller.FindBodyMaxMass();
			controller.FindBodyMinMass();
			cout << endl;
			cout << "All shapes" << endl;
			for (auto i : controller.GetAllShape())
			{
				cout << i->ToString() << endl;
			}
			break;
		}
	}

    return 0;
}

