// 03.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

void Fib(int num)
{
	int oldValue = 1;
	int value = 0;
	int hold;
	int counter = 1;
	
	while (value < num)
	{
		if (value != 0 && counter % 5 != 1) {
			cout << ", ";
		}
		cout << value;
		if (counter % 5 == 0)
			cout << endl;
		
		hold = value;
		value += oldValue;
		oldValue = hold;

		counter++;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		return 1;
	}
	int number = strtol(argv[1], nullptr, 10);
	if ((number >= 1) && (number < INT_MAX))
	{
		Fib(number);
	}
	else 
		cout << "Number is not set correctly!" << endl;

	return 0;
}

