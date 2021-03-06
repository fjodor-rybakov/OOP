// VolumetricShapeTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../VolumetricShape/BodyController.h"
#include "../VolumetricShape/CBody.h"
#include "../VolumetricShape/CCylinder.h"
#include "../VolumetricShape/CSphere.h"
#include "../VolumetricShape/CParallelepiped.h"
#include "../VolumetricShape/CCone.h"
#include "../VolumetricShape/CCompound.h"

using namespace std;

TEST_CASE("TEST_VOLUMETRIC_SHAPES")
{
	BodyController controller;
	SECTION("Create sphere")
	{
		CSphere sphere(10, 1000);
		CHECK(sphere.GetType() == "Sphere");
		CHECK(sphere.GetDensity() == 1000);
		CHECK(sphere.GetRadius() == 10);
		CHECK(sphere.GetMass() == 3141593.0);
		CHECK(sphere.GetVolume() == 3141.593);
	}

	SECTION("Create parallelepiped")
	{
		CParallelepiped parallelepiped(20, 10, 5, 700);
		CHECK(parallelepiped.GetType() == "Parallelepiped");
		CHECK(parallelepiped.GetDensity() == 700);
		CHECK(parallelepiped.GetMass() == 700000);
		CHECK(parallelepiped.GetVolume() == 1000);
	}

	SECTION("Create cone")
	{
		CCone cone(10, 20, 600);
		CHECK(cone.GetType() == "Cone");
		CHECK(cone.GetDensity() == 600);
		CHECK(cone.GetBaseRadius() == 10);
		CHECK(cone.GetHeight() == 20);
		CHECK(cone.GetMass() == 1256637.0);
		CHECK(cone.GetVolume() == 2094.395);
	}

	SECTION("Create cylinder")
	{
		CCylinder cylinder(30, 5, 500);
		CHECK(cylinder.GetType() == "Cylinder");
		CHECK(cylinder.GetDensity() == 500);
		CHECK(cylinder.GetBaseRadius() == 30);
		CHECK(cylinder.GetHeight() == 5);
		CHECK(cylinder.GetMass() == 7068583.5);
		CHECK(cylinder.GetVolume() == 14137.167);
	}

	SECTION("Create compund")
	{
		CCompound compound;
		CHECK(compound.AddChildBody(shared_ptr<CBody>(new CSphere(10, 1000))) == true);
		CHECK(compound.AddChildBody(shared_ptr<CBody>(new CParallelepiped(20, 10, 5, 700))) == true);
		CHECK(compound.AddChildBody(shared_ptr<CBody>(new CCone(10, 20, 600))) == true);
		CHECK(compound.AddChildBody(shared_ptr<CBody>(new CCylinder(30, 5, 500))) == true);
		CHECK(compound.GetType() == "Compound");
		CHECK(compound.GetDensity() == 597.198);
		CHECK(compound.GetMass() == 12166813.5);
		CHECK(compound.GetVolume() == 20373.155);
	}

	SECTION("Add your self")
	{
		shared_ptr<CCompound> scompound(new CCompound);
		CHECK(scompound->AddChildBody(scompound) == false);
	}

	SECTION("Add comp and your self")
	{
		shared_ptr<CCompound> scompound(new CCompound);
		shared_ptr<CCompound> scomp(new CCompound);
		shared_ptr<CCompound> scomp1(new CCompound);
		controller.AddShape(scompound);
		controller.AddShape(scomp);
		controller.AddShape(scomp1);
		CHECK(scompound->AddChildBody(scomp) == true);
		CHECK(scompound->AddChildBody(scomp1) == true);
		CHECK(scomp1->AddChildBody(scomp1) == false);
		CHECK(scompound->AddChildBody(scompound) == false);
	}

	SECTION("Find min mass elem on water")
	{
		shared_ptr<CBody> sphere(new CSphere(10, 1000));
		shared_ptr<CBody> parallelepiped(new CParallelepiped(20, 10, 5, 700));
		shared_ptr<CBody> cone(new CCone(10, 20, 600));
		controller.AddShape(sphere);
		controller.AddShape(parallelepiped);
		controller.AddShape(cone);
		CHECK(controller.FindBodyMaxMass() == sphere);
		CHECK(controller.FindBodyMaxMass()->GetMass() == 3141593.0);
		CHECK(controller.FindBodyMaxMass()->GetType() == "Sphere");
	}

	SECTION("Find max mass elem")
	{
		shared_ptr<CBody> sphere(new CSphere(10, 1000));
		shared_ptr<CBody> parallelepiped(new CParallelepiped(20, 10, 5, 700));
		shared_ptr<CBody> cone(new CCone(10, 20, 600));
		controller.AddShape(sphere);
		controller.AddShape(parallelepiped);
		controller.AddShape(cone);
		CHECK(controller.FindBodyMinMass() == cone);
		CHECK(controller.FindBodyMinMass()->GetMass() == 1256637.0);
		CHECK(controller.FindBodyMinMass()->GetType() == "Cone");
	}
}