#pragma once

class CCar
{
public:
	CCar();
	bool TurnOnEngine();
	bool TurnOffEngine();
	int GetSpeed() const;
	int GetGear() const;
	bool StateEngine() const;
	std::string Direction() const;
	bool SetGear(int gear);
	bool SetSpeed(int speed);
private:
	int m_gear, m_speed;
	bool m_isOn;
};