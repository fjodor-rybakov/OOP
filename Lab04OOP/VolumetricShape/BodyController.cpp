#include "stdafx.h"
#include "BodyController.h"
#include "CSphere.h"
#include "CCone.h"
#include "CParallelepiped.h"
#include "CCylinder.h"
#include "CCompound.h"

using namespace std;

shared_ptr<CSphere> BodyController::AddSphere()
{
	cout << "Please enter radius and density" << endl;
	cin >> radius >> density;
	shared_ptr<CSphere> ssphere(new CSphere(radius, density));
	if (!isCompound)
		AddShape(ssphere);
	
	return ssphere;
}

shared_ptr<CParallelepiped> BodyController::AddParallelepiped()
{
	cout << "Please enter width, height, depth and density" << endl;
	cin >> width >> height >> depth >> density;
	shared_ptr<CParallelepiped> sparallelepiped(new CParallelepiped(width, height, depth, density));
	if (!isCompound)
		AddShape(sparallelepiped);
	
	return sparallelepiped;
}

shared_ptr<CCone> BodyController::AddCone()
{
	cout << "Please enter baseRadius, height and density" << endl;
	cin >> baseRadius >> height >> density;
	shared_ptr<CCone> scone(new CCone(baseRadius, height, density));
	if (!isCompound)
		AddShape(scone);

	return scone;
}

shared_ptr<CCylinder> BodyController::AddCylinder()
{
	cout << "Please enter baseRadius, height and density" << endl;
	cin >> baseRadius >> height >> density;
	shared_ptr<CCylinder> scylinder(new CCylinder(baseRadius, height, density));
	if (!isCompound)
		AddShape(scylinder);

	return scylinder;
}

shared_ptr<CCompound> BodyController::AddCompound()
{
	shared_ptr<CCompound> scompound(new CCompound);
	string command;
	cout << "Please enter shapes" << endl;
	cout << "Command Stop for exit" << endl;
	cout << "Command Sphere - add shpere" << endl;
	cout << "Command Parallelepiped - add parallelepiped" << endl;
	cout << "Command Cone - add cone" << endl;
	cout << "Command Cylinder - add cone" << endl;
	cout << "Command Compound - add cone" << endl;
	isCompound++;
	while (true)
	{
		cin >> command;
		if (command == "Sphere")
		{
			scompound->AddChildBody(AddSphere());
		}
		else if (command == "Parallelepiped")
		{
			scompound->AddChildBody(AddParallelepiped());
		}
		else if (command == "Cone")
		{
			scompound->AddChildBody(AddCone());
		}
		else if (command == "Cylinder")
		{
			scompound->AddChildBody(AddCylinder());
		}
		else if (command == "Compound")
		{
			scompound->AddChildBody(AddCompound());
		}
		else if (command == "Stop")
		{
			isCompound--;
			break;
		}
	}

	if (isCompound == 1)
		AddShape(scompound);

	return scompound;
}

void BodyController::FindBodyMaxMass()
{
	double maxMass = 0;
	std::shared_ptr<CBody> maxMassElemPtr = nullptr;
	if (!allShape.empty())
	{
		for (auto i : allShape)
		{
			if (maxMass < i->GetMass())
			{
				maxMass = i->GetMass();
				maxMassElemPtr = i;
			}
		}

		cout << "MaxMass: " << maxMass << endl;
		cout << "Shape: " << maxMassElemPtr->GetType() << endl;
	}
	else
	{
		cout << "Not found shapes!" << endl;
	}
}

void BodyController::FindBodyMinMass()
{
	double minMass = numeric_limits<double>::has_infinity;
	std::shared_ptr<CBody> minMassElemPtr = nullptr;
	if (!allShape.empty())
	{
		for (auto i : allShape)
		{
			if (minMass > (i->GetDensity() - M_PW) *  M_G * i->GetVolume())
			{
				minMass = (i->GetDensity() - M_PW) *  M_G * i->GetVolume();
				minMassElemPtr = i;
			}
		}

		cout << "MinMass: " << minMass << endl;
		cout << "Shape: " << minMassElemPtr->GetType() << endl;
	}
	else
	{
		cout << "Not found shapes!" << endl;
	}
}

void BodyController::AddShape(std::shared_ptr<CBody> elem)
{
	allShape.push_back(move(elem));
}

std::vector<std::shared_ptr<CBody>> BodyController::GetAllShape() const
{
	return allShape;
}
