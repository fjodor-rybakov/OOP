#include "stdafx.h"
#include "CCompound.h"
#include "BodyController.h"
#include "iostream"

CCompound::CCompound() : CBody("Compound")
{
}

bool CCompound::AddChildBody(std::shared_ptr<CBody> child)
{
	bool isCreate = false;
	if (CheckShapes(child))
	{
		std::cout << "Can not add yourself" << std::endl;
		return isCreate;
	}
	if (child.get() == this)
	{
		std::cout << "Can not add yourself" << std::endl;
		return isCreate;
	}
	if (child != nullptr)
	{
		m_compoundArray.push_back(move(child));
		isCreate = true;
	}
	else
	{
		std::cout << "Incorrect shape!" << std::endl;
	}
	return isCreate;
}

void CCompound::GetInfo()
{
	std::cout << "Mass: " << CCompound::GetMass() << std::endl;
	std::cout << "Volume: " << CCompound::GetVolume() << std::endl;
	std::cout << "Density: " << CCompound::GetDensity() << std::endl;
}

double CCompound::GetMass() const
{
	double mass = 0;
	for (auto elem : m_compoundArray)
	{
		mass += elem->GetMass();
	}
	
	return mass;
}

double CCompound::GetVolume() const
{
	double volume = 0;
	for (auto elem : m_compoundArray)
	{
		volume += elem->GetVolume();
	}

	return volume;
}

double CCompound::GetDensity() const
{
	return GetMass() / GetVolume();
}

bool CCompound::CheckShapes(std::shared_ptr<CBody> child)
{
	bool checkS = false;
	BodyController bc;
	for (auto i : bc.GetAllShape())
	{
		if (child == i && i->GetType() == "Compound")
		{
			checkS = true;
			break;
		}
	}
	return checkS;
}