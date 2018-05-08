#pragma once
#include "CBody.h"

class CCylinder : public CBody
{
public:
	CCylinder(double baseRadius, double height, double density);
	double GetDensity() const;
	double GetVolume() const override;
	double GetMass() const;
	double GetBaseRadius() const;
	double GetHeight() const;
	void GetInfo() const;
private:
	double m_baseRadius, m_height;
};