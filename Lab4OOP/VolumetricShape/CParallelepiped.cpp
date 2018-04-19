#include "stdafx.h"
#include "CParallelepiped.h"

CParallelepiped::CParallelepiped(double width, double height, double depth, double density) : 
	CBody("Parallelepiped", density),
	m_width(width),
	m_height(height),
	m_depth(depth)
{
}

double CParallelepiped::GetDensity() const
{
	return CBody::GetDensity();
}

double CParallelepiped::GetVolume() const
{
	return m_width * m_height * m_depth;
}

double CParallelepiped::GetMass() const
{
	return CBody::GetMass();
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

void CParallelepiped::GetInfo() const
{
	std::cout << CBody::ToString() << std::endl;
	std::cout << "Width: " << GetWidth() << std::endl;
	std::cout << "Height: " << GetHeight() << std::endl;
	std::cout << "Depth: " << GetDepth() << std::endl;
	std::cout << std::endl;
}