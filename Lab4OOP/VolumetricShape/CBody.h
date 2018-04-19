#pragma once
#include "string"

class CBody
{
public:
	CBody(const std::string &type, double density);
	double GetDensity() const;
	virtual double GetVolume() const;
	double GetMass() const;
	std::string ToString() const;
private:
	double m_density = 0;
	std::string m_type;
};