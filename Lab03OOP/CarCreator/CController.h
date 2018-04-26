#pragma once
#include "CCar.h"

class CController
{
public:
	CController(CCar & car);
	void Info();
	bool EngineOn();
	bool EngineOff();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
private:
	CCar & m_car;
};