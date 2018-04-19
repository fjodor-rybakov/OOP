#pragma once
#include "CBody.h"
#include "vector"
#include "memory"

class CCompound : public CBody 
{
public:
	CCompound();
	bool AddChildBody(CBody shape);
	void GetInfo() const;
private:
	std::vector<std::shared_ptr<CBody>> m_compoundArray;
	double m_density = 0;
};