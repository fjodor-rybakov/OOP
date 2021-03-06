// PrimeNumGeneratorTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../PrimeNumGenerator/Generator.h"
#include "set"

using namespace std;

long long numOne = 10000;
long long expextOne = 1229;

long long numTwo = 4657;
long long expextTwo = 630;

long long numThree = 253456;
long long expextThree = 22311;

long long numFour = 100000000;
long long expextFour = 5761455;

TEST_CASE("Test set")
{
	CHECK(GeneratePrimeNumbersSet(numOne).size() == expextOne);
	CHECK(GeneratePrimeNumbersSet(numTwo).size() == expextTwo);
	CHECK(GeneratePrimeNumbersSet(numThree).size() == expextThree);
	CHECK(GeneratePrimeNumbersSet(numFour).size() == expextFour);
}