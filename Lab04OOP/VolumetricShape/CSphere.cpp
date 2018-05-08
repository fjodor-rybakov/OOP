#include "stdafx.h"
#include "CSphere.h"

CSphere::CSphere(double radius, double density) : 
	CBody("Sphere", density),
	m_radius(radius)
{
}

double CSphere::GetRadius() const
{
	return m_radius;
}

double CSphere::GetDensity() const
{
	return CBody::GetDensity();
}

double CSphere::GetVolume() const
{
	return 4 / 3 * M_PI * pow(m_radius, 3);
}

double CSphere::GetMass() const
{
	return CBody::GetMass();
}

void CSphere::GetInfo() const
{
	std::cout << ToString() << std::endl;
	std::cout << "Radius: " << GetRadius() << std::endl;
	std::cout << std::endl;
}