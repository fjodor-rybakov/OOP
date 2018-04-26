#include "stdafx.h"
#include "CCompound.h"

CCompound::CCompound() : CBody("Compound", m_density)
{
}

bool CCompound::AddChildBody(CBody child)
{
	std::shared_ptr<CBody> shape = std::make_shared<CBody>(child);
	bool isCreate = false;
	if (shape != nullptr)
	{
		m_compoundArray.push_back(shape);
		isCreate = true;
		std::cout << "Successful add shape!" << std::endl;
	}
	else
	{
		std::cout << "Incorrect shape!" << std::endl;
	}
	return isCreate;
}

void CCompound::GetInfo() const
{
	for (auto elem : m_compoundArray)
	{
		std::cout << elem->ToString() << std::endl;
	}
}