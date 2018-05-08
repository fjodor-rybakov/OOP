#pragma once
#include "CBody.h"
#include "vector"
#include "memory"

class CCompound : public CBody 
{
public:
	CCompound();
	bool AddChildBody(std::shared_ptr<CBody> child);
	void GetInfo();
	double GetMass() const;
	double GetVolume() const;
	double GetDensity() const;
private:
	bool CheckShapes(std::shared_ptr<CBody> child);
	std::vector<std::shared_ptr<CBody>> m_compoundArray;
};