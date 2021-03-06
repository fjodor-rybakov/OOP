#include "stdafx.h"
#include "CBody.h"

using namespace std;

CBody::CBody(const std::string& type)
	: m_type(type)
{
}

CBody::CBody(const string &type, double density) :
	m_density(density),
	m_type(type)
{
}

double CBody::GetDensity() const
{
	return m_density;
}

double CBody::GetVolume() const
{
	return m_volume;
}

double CBody::GetMass() const
{
	return GetVolume() * GetDensity();
}

std::string CBody::ToString() const
{
	std::string resilt_str = "Figure - " + m_type + "\n" +
		"Density: " + to_string(GetDensity()) + "\n" +
		"Volume: " + to_string(GetVolume()) + "\n" +
		"Mass: " + to_string(GetMass());
	return resilt_str;
}

std::string CBody::GetType() const
{
	return m_type;
}