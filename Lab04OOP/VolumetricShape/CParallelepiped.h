#pragma once
#include "CBody.h"

class CParallelepiped : public CBody
{
public:
	CParallelepiped(double width, double height, double depth, double density);
	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	double GetVolume() const override;
	double GetDensity() const;
	double GetMass() const;
	void GetInfo() const;
private:
	double m_width, m_height, m_depth;
};