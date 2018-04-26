#include "stdafx.h"
#include "CCar.h"
#include "map"
#include "iostream"

using namespace std;

map<int, pair<int, int>> mapRangeSpeed = {
	{ -1, make_pair(0, 20) },
	{ 0, make_pair(0, 150) },
	{ 1, make_pair(0, 30) },
	{ 2, make_pair(20, 50) },
	{ 3, make_pair(30, 60) },
	{ 4, make_pair(40, 90) },
	{ 5, make_pair(50, 150) }
};

CCar::CCar() : 
	m_gear(0), 
	m_speed(0),
	m_isOn(false)
{
}

bool CCar::TurnOnEngine()
{
	return !m_isOn ? m_isOn = true : false;
}

bool CCar::TurnOffEngine()
{
	bool checker = false;
	if (m_gear == 0 && m_speed == 0 && m_isOn)
	{
		checker = true;
		m_isOn = false;
	}
	return checker;
}

bool CCar::SetGear(int gear)
{
	bool check = false;
	if (!m_isOn && gear == 0)
	{
		m_gear = gear;
		check = true;
		return check;
	}
	else if (!m_isOn)
	{
		cout << "You can not switch gears when the engine is off" << endl;
		return check;
	}
	if (gear == -1 && m_speed == 0)
	{
		m_gear = gear;
		check = true;
		return check;
	}
	if (m_gear == 0 && m_speed != 0)
	{
		cout << "To switch to another speed from neutral gear, it is necessary to completely stop" << endl;
		return check;
	}
	if (m_gear == -1)
	{
		if ((gear == 1 && m_speed == 0) || (gear == 0))
		{
			m_gear = gear;
			check = true;
			return check;
		}
		else
		{
			cout << "From the reverse, you can only switch to 0 and 1 gears" << endl;
			return check;
		}
	}
	if (m_speed >= mapRangeSpeed[gear].first && m_speed <= mapRangeSpeed[gear].second)
	{
		m_gear = gear;
		check = true;
	}
	else
	{
		cout << "The current speed is less than the minimum or greater than the maximum allowed on this gear" << endl;
	}

	return check;
}

bool CCar::SetSpeed(int speed)
{
	bool check = false;
	if (!m_isOn)
	{
		cout << "It is impossible to switch the speed when the engine is off" << endl;
		return check;
	}
	if (m_gear == 0)
	{
		if (m_speed >= speed)
		{
			m_speed = speed;
			check = true;
			return check;
		}
		else
		{
			cout << "At neutral transmission, the speed can only decrease" << endl;
			return check;
		}
	}
	if (speed >= mapRangeSpeed[m_gear].first && speed <= mapRangeSpeed[m_gear].second)
	{
		m_speed = speed;
		check = true;
	}
	else
	{
		cout << "The selected speed is greater than the specified maximum or less than the minimum" << endl;
	}

	return check;
}

int CCar::GetGear() const
{
	return m_speed;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

bool CCar::StateEngine() const
{
	return m_isOn;
}

std::string CCar::Direction() const
{
	string result;
	if (m_gear == -1)
	{
		result = "back";
	}
	else if (m_gear == 0)
	{
		result = "resting";
	}
	else
	{
		result = "forward";
	}
	return result;
}