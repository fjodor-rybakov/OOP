// PrimeNumGenerator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "set"
#include "iostream"
#include "vector"
#include "Generator.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Incorrect get input" << endl;
		cout << "PrimeNumGenerator.exe <max number>" << endl;
		return 1;
	}

	long long maxNum = atoi(argv[1]);

	//cout << GeneratePrimeNumbersSet(maxNum).size() << endl;

	for (auto i : GeneratePrimeNumbersSet(maxNum))
		cout << i << endl;

    return 0;
}

