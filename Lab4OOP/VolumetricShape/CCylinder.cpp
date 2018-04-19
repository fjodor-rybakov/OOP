#include "stdafx.h"
#include "CCylinder.h"

CCylinder::CCylinder(double baseRadius, double height, double density) :
	CBody("Cylinder", density),
	m_baseRadius(baseRadius),
	m_height(height)
{
}

double CCylinder::GetDensity() const
{
	return CBody::GetDensity();
}

double CCylinder::GetVolume() const
{
	return M_PI * pow(m_baseRadius, 2) * m_height;
}

double CCylinder::GetMass() const
{
	return CBody::GetMass();
}

double CCylinder::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

void CCylinder::GetInfo() const
{
	std::cout << CBody::ToString() << std::endl;
	std::cout << "BaseRadius: " << GetBaseRadius() << std::endl;
	std::cout << "Height: " << GetHeight() << std::endl;
	std::cout << std::endl;
}
