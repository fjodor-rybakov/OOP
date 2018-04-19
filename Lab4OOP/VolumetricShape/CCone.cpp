#include "stdafx.h"
#include "CCone.h"

CCone::CCone(double baseRadius, double height, double density) : 
	CBody("Cone", density),
	m_baseRadius(baseRadius),
	m_height(height)
{
}

double CCone::GetDensity() const
{
	return CBody::GetDensity();
}

double CCone::GetVolume() const
{
	return M_PI * pow(m_baseRadius, 2) * m_height * 1 / 3;
}

double CCone::GetMass() const
{
	return CBody::GetMass();
}

double CCone::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCone::GetHeight() const
{
	return m_height;
}

void CCone::GetInfo() const
{
	std::cout << CBody::ToString() << std::endl;
	std::cout << "BaseRadius: " << GetBaseRadius() << std::endl;
	std::cout << "Height: " << GetHeight() << std::endl;
	std::cout << std::endl;
}

