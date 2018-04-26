#pragma once
#include "CBody.h"

class CSphere final : public CBody
{
public:
	CSphere(double radius, double density);
	double GetRadius() const;
	double GetDensity() const;
	double GetVolume() const override;
	double GetMass() const;
	void GetInfo() const;
private:
	double m_radius = 0;
};