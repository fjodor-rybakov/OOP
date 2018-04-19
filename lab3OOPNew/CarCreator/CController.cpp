#include "stdafx.h"
#include "CController.h"
#include "iostream"
#include "string"

using namespace std;

CController::CController(CCar & car) :
	m_car(car)
{
}

void CController::Info()
{
	cout << "State engine: " << m_car.StateEngine() << endl;
	cout << "Direction of travel: " << m_car.Direction() << endl;
	cout << "Speed: " << m_car.GetSpeed() << endl;
	cout << "Gear: " << m_car.GetGear() << endl;
}

bool CController::EngineOn()
{
	return m_car.TurnOnEngine();
}

bool CController::EngineOff()
{
	return m_car.TurnOffEngine();
}

bool CController::SetGear(int gear)
{
	return m_car.SetGear(gear);
}

bool CController::SetSpeed(int speed)
{
	return m_car.SetSpeed(speed);
}