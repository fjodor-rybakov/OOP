// Vector3DTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "../Vector3D/CVector3D.h"

using namespace std;


TEST_CASE("TEST_MY_VECTOR3D")
{
	SECTION("Check create zero 3D vector") // Проверка на создание нулевого 3D вектора
	{
		cout << "Check create zero 3D vector" << endl;
		CVector3D myVector3D;
		CHECK(myVector3D.x == 0);
		CHECK(myVector3D.y == 0);
		CHECK(myVector3D.z == 0);
	}

	SECTION("Check create 3D vector") // Проверка на создание 3D вектора 
	{
		cout << "Check create 3D vector" << endl;
		CVector3D myVector3D(10, 20, 30);
		CHECK(myVector3D.x == 10);
		CHECK(myVector3D.y == 20);
		CHECK(myVector3D.z == 30);
	}

	SECTION("Check length") // Проверяем на длину 
	{
		cout << "Check length" << endl;
		CVector3D myVector3D(10, 20, 30);
		CHECK(myVector3D.GetLength() == 37.417);
		myVector3D.ChangeVector3D(30, 30, 30);
		CHECK(myVector3D.GetLength() == 51.962);
	}

	SECTION("Check normalize") // Проверяем приведение вектора к нормализации
	{
		cout << "Check normalize" << endl;
		CVector3D myVector3D(30, 30, 30);
		myVector3D.Normalize();
		CHECK(myVector3D.x == 0.570);
		CHECK(myVector3D.y == 0.570);
		CHECK(myVector3D.z == 0.570);
	}

	SECTION("Unary plus overloading") // Перегрузка унарного плюса
	{
		cout << "Unary plus overloading" << endl;
		CVector3D myVector3D(30, 30, 30);
		+myVector3D;
		CHECK(myVector3D.x == 30);
		CHECK(myVector3D.y == 30);
		CHECK(myVector3D.z == 30);
	}

	SECTION("Overload unary minus") // Перегрузка унарного минуса
	{
		cout << "Overload unary minus" << endl;
		CVector3D myVector3D(30, 30, 30);
		myVector3D = -myVector3D;
		CHECK(myVector3D.x == -30);
		CHECK(myVector3D.y == -30);
		CHECK(myVector3D.z == -30);
	}

	SECTION("Overload binary plus") // Перегрузка бинарного оператора +
	{
		cout << "Overload binary plus" << endl;
		CVector3D myVector3DFirst(30, 30, 30), myVector3DSecond(10, 20, 30), resultVector3D;
		resultVector3D = myVector3DFirst + myVector3DSecond;
		CHECK(resultVector3D.x == 40);
		CHECK(resultVector3D.y == 50);
		CHECK(resultVector3D.z == 60);
	}

	SECTION("Overload binary minus") // Перегрузка бинарного оператора -
	{
		cout << "Overload binary minus" << endl;
		CVector3D myVector3DFirst(30, 30, 30), myVector3DSecond(10, 20, 30), resultVector3D;
		resultVector3D = myVector3DFirst - myVector3DSecond;
		CHECK(resultVector3D.x == 20);
		CHECK(resultVector3D.y == 10);
		CHECK(resultVector3D.z == 0);
	}

	SECTION("Overload operator +=") // Перегрузка оператора +=
	{
		cout << "Overload operator +=" << endl;
		CVector3D myVector3DFirst(30, 30, 30), myVector3DSecond(10, 20, 30);
		myVector3DFirst += myVector3DSecond;
		CHECK(myVector3DFirst.x == 40);
		CHECK(myVector3DFirst.y == 50);
		CHECK(myVector3DFirst.z == 60);

	}

	SECTION("Overload operator -=") // Перегрузка оператора -=
	{
		cout << "Overload operator -=" << endl;
		CVector3D myVector3DFirst(30, 30, 30), myVector3DSecond(10, 20, 30);
		myVector3DFirst -= myVector3DSecond;
		CHECK(myVector3DFirst.x == 20);
		CHECK(myVector3DFirst.y == 10);
		CHECK(myVector3DFirst.z == 0);
	}

	SECTION("Overload operator *") // Перегрузка оператора *
	{
		cout << "Overload operator *" << endl;
		CVector3D myVector3D(20, 40, 60);
		double scalar = 10;
		myVector3D = myVector3D * scalar;
		CHECK(myVector3D.x == 200);
		CHECK(myVector3D.y == 400);
		CHECK(myVector3D.z == 600);
		scalar = 2;
		myVector3D = scalar * myVector3D;
		CHECK(myVector3D.x == 400);
		CHECK(myVector3D.y == 800);
		CHECK(myVector3D.z == 1200);
	}

	SECTION("Overload operator /") // Перегрузка оператора /
	{
		cout << "Overload operator /" << endl;
		CVector3D myVector3D(20, 40, 60);
		double scalar = 20;
		myVector3D = myVector3D / scalar;
		CHECK(myVector3D.x == 1);
		CHECK(myVector3D.y == 2);
		CHECK(myVector3D.z == 3);
	}

	SECTION("Overload operator *=") // Перегрузка оператора *=
	{
		cout << "Overload operator *=" << endl;
		CVector3D myVector3D(1, 5, 10);
		double scalar = 20;
		myVector3D *= scalar;
		CHECK(myVector3D.x == 20);
		CHECK(myVector3D.y == 100);
		CHECK(myVector3D.z == 200);
	}

	SECTION("Overload operator /=") // Перегрузка оператора /=
	{
		cout << "Overload operator /=" << endl;
		CVector3D myVector3D(100, 200, 400);
		double scalar = 20;
		myVector3D /= scalar;
		CHECK(myVector3D.x == 5);
		CHECK(myVector3D.y == 10);
		CHECK(myVector3D.z == 20);
	}

	SECTION("Overload operator ==") // Перегрузка оператора ==
	{
		cout << "Overload operator ==" << endl;
		CVector3D myVector3DOne(20.0, 40.0, 60.0), myVector3DTwo(100.0, 50.0, 10.0), myVector3DThree(20.0, 40.0, 60.0);
		CHECK(!(myVector3DOne == myVector3DTwo));
		CHECK(myVector3DOne == myVector3DThree);
	}

	SECTION("Overload operator !=") // Перегрузка оператора !=
	{
		cout << "Overload operator !=" << endl;
		CVector3D myVector3DOne(20, 40, 60), myVector3DTwo(100, 50, 10), myVector3DThree(20, 40, 60);
		CHECK(myVector3DOne != myVector3DTwo);
		CHECK(!(myVector3DOne != myVector3DThree));
	}

	SECTION("Scalar product of vectors") // Скалярное произведение векторов
	{
		cout << "Scalar product of vectors" << endl;
		CVector3D myVector3DOne(20, 40, 60), myVector3DTwo(100, 50, 10);
		CHECK(CVector3D::DotProduct(myVector3DOne, myVector3DTwo) == 4600);
	}

	SECTION("Vector product of vectors") // Вектороное произведение векторов
	{
		cout << "Vector product of vectors" << endl;
		CVector3D myVector3DOne(20.0, 40.0, 60.0), myVector3DTwo(100.0, 50.0, 10.0), myVector3DThree(-2600.0, 5800.0, 600.0);
		CHECK(CVector3D::CrossProduct(myVector3DOne, myVector3DTwo) == myVector3DThree);
	}

	SECTION("Normalize on param")
	{
		cout << "Vector product of vectors" << endl;
		CHECK(CVector3D(0.26, 0.52, 0.78) == CVector3D::Normalize(CVector3D(20.0, 40.0, 60.0)));
	}
	//cin.get();
}