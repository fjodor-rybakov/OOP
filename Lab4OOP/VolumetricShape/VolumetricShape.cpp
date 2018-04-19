// VolumetricShape.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CSphere.h"
#include "CParallelepiped.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CCompound.h"

using namespace std;

int main()
{
	CSphere sphere(10, 1200);
	sphere.GetInfo();
	CParallelepiped parallelepiped(10, 20, 30, 1100);
	parallelepiped.GetInfo();
	//CCone cone(5, 20, 1500);
	//cone.GetInfo();
	//CCylinder cylinder(10, 40, 900);
	//cylinder.GetInfo();
	CCompound compound;
	compound.AddChildBody(sphere);
	compound.AddChildBody(parallelepiped);
	compound.GetInfo();


    return 0;
}

