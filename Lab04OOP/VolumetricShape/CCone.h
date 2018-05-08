#pragma once
#include "CBody.h"

class CCone : public CBody
{
public:
	CCone(double baseRadius, double height, double density);
	double GetDensity() const;
	double GetVolume() const override;
	double GetMass() const;
	double GetBaseRadius() const;
	double GetHeight() const;
	void GetInfo() const;
private:
	double m_baseRadius, m_height;
};