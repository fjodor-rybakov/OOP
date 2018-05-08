#pragma once
#include "string"
#include "vector"

class CBody
{
public:
	CBody(const std::string &type);
	CBody(const std::string &type, double density);

	virtual double GetDensity() const;
	virtual double GetVolume() const;
	double GetMass() const;
	std::string ToString() const;
	std::string GetType() const;
private:
	double m_density, m_volume = 0, m_mass = 0;
	std::string m_type;
};