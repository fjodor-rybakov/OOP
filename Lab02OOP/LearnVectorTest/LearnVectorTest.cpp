// LearnVectorTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "../LearnVector/DivMaxHalf.h"

using namespace std;

vector<double> baseVector0 = {0};
vector<double> expectVector0 = { 0 };

vector<double> baseVector1 = { 1, 2, 3 };
vector<double> expectVector1 = { 1.5, 3.0, 4.5 };

vector<double> baseVector2 = { 5.5, 8, 6.2 };
vector<double> expectVector2 = { 22, 32, 24.8 };

vector<double> baseVector3 = { 156.4356, 200.00, 54.228 };
vector<double> expectVector3 = { 15643.56, 20000, 5422.8 };

vector<double> baseVector4 = { 5.5, 8, 6.2 };
vector<double> expectVector4 = { 22, 24.8, 32 };

TEST_CASE("Test vector")
{
	DivMaxHalf(baseVector1);
	CHECK(baseVector1 == expectVector1);
	DivMaxHalf(baseVector2);
	CHECK(baseVector2 == expectVector2);
	DivMaxHalf(baseVector3);
	CHECK(baseVector3 == expectVector3);
	DivMaxHalf(baseVector4);
	sort(baseVector4.begin(), baseVector4.end());
	CHECK(baseVector4 == expectVector4);
}