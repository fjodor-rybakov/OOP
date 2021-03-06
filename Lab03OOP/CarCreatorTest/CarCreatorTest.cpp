// CarCreatorTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../CarCreator/CController.h"
#include "../CarCreator/CCar.h"

CCar audi;
CController controllerAudi(audi);

TEST_CASE("Test car")
{
	SECTION("Check On / Off") // проверка включения, выключения
	{
		CHECK(controllerAudi.EngineOn() == true);
		CHECK(controllerAudi.EngineOn() == false);
		CHECK(controllerAudi.EngineOff() == true);
		CHECK(controllerAudi.EngineOff() == false);
	}

	SECTION("Try to switch the speed or gear with the engine off") // Пробуем переключить скорость или передачу при выключенном двигателе
	{
		CHECK(controllerAudi.SetGear(1) == false);
		CHECK(controllerAudi.SetGear(0) == true);
		CHECK(controllerAudi.SetGear(4) == false);
		CHECK(controllerAudi.SetSpeed(10) == false);
		CHECK(controllerAudi.SetSpeed(124) == false);
	}

	SECTION("An attempt to turn the engine on and off at non-zero speed and transmission") // Попытка включить и отключить двигатель на ненулевой скорости и передаче
	{
		CHECK(controllerAudi.EngineOn() == true);
		CHECK(controllerAudi.SetGear(1) == true);
		CHECK(controllerAudi.SetSpeed(10) == true);
		CHECK(controllerAudi.EngineOff() == false);
	}

	SECTION("Attempt to set an incorrect transfer or speed") // Попытка установить неверную передачу или скорость
	{
		CHECK(controllerAudi.SetGear(7) == false);
		CHECK(controllerAudi.SetSpeed(160) == false);
	}

	SECTION("Trying to change the speed to a greater or lesser in the zero gear") //Попытка изменить скорость на большую или меньшую на нулевой передаче
	{
		CHECK(controllerAudi.SetGear(0) == true);
		CHECK(controllerAudi.SetSpeed(10) == true);
		CHECK(controllerAudi.SetSpeed(11) == false);
		CHECK(controllerAudi.SetSpeed(6) == true);
		CHECK(controllerAudi.SetSpeed(0) == true);
	}

	SECTION("Check the gears for their assigned speeds") // Проверяем передачи на отведённые для них скорости
	{
		CHECK(controllerAudi.SetGear(1) == true);
		CHECK(controllerAudi.SetSpeed(21) == true);
		CHECK(controllerAudi.SetSpeed(61) == false);
		CHECK(controllerAudi.SetGear(2) == true);
		CHECK(controllerAudi.SetSpeed(45) == true);
		CHECK(controllerAudi.SetGear(4) == true);
	}

	SECTION("Try to switch from any transfer to zero") // Пробуем переключиться с любой передачи на нулевую
	{
		CHECK(controllerAudi.SetGear(0) == true);
		CHECK(controllerAudi.SetSpeed(61) == false);
		CHECK(controllerAudi.SetSpeed(21) == true);
		CHECK(controllerAudi.SetSpeed(0) == true);
	}

	SECTION("Try to switch to the reverse with a non-zero speed") // Пробуем переключиться на задний ход с ненулевой скорости
	{
		CHECK(controllerAudi.SetGear(1) == true);
		CHECK(controllerAudi.SetSpeed(21) == true);
		CHECK(controllerAudi.SetGear(-1) == false);
	}

	SECTION("Try to switch to reverse when moving backwards") // Пробуем переключиться на задний ход при движении назад
	{
		CHECK(controllerAudi.SetGear(0) == true);
		CHECK(controllerAudi.SetSpeed(0) == true);
		CHECK(controllerAudi.SetGear(-1) == true);
		CHECK(controllerAudi.SetSpeed(10) == true);
		CHECK(controllerAudi.SetGear(0) == true);
		CHECK(controllerAudi.SetGear(-1) == false);
	}

	SECTION("Try to switch from reverse to first gear at non-zero speed") // пробуем переключиться с заднего хода на первую передачу на ненулевой скорости
	{
		CHECK(controllerAudi.SetSpeed(0) == true);
		CHECK(controllerAudi.SetGear(-1) == true);
		CHECK(controllerAudi.SetGear(-1) == true);
		CHECK(controllerAudi.SetSpeed(10) == true);
		CHECK(controllerAudi.SetGear(1) == false);
	}

	SECTION("We try to switch from reverse to 0 gear, and then to the first at non-zero speed") // Пробуем переключиться с заднего хода на 0 передачу, а затем на первую на ненулевой скорости
	{
		CHECK(controllerAudi.SetGear(0) == true);
		CHECK(controllerAudi.SetGear(1) == false);
		CHECK(controllerAudi.SetGear(2) == false);
		CHECK(controllerAudi.SetGear(3) == false);
		CHECK(controllerAudi.SetSpeed(0) == true);
		CHECK(controllerAudi.SetGear(1) == true);
	}

	SECTION("Try to turn off the car at a non-zero speed and transfer") // Пробуем выключить автомобиль на ненулевой скорости и передаче
	{
		CHECK(controllerAudi.SetGear(1) == true);
		CHECK(controllerAudi.SetSpeed(21) == true);
		CHECK(controllerAudi.EngineOff() == false);
	}

	SECTION("Turn off engine") // Выключаем двигатель
	{
		CHECK(controllerAudi.SetGear(0) == true);
		CHECK(controllerAudi.SetSpeed(0) == true);
		CHECK(controllerAudi.EngineOff() == true);
	}
}