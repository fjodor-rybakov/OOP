// flipbyte.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int StringToInt(const char* str, bool & err)
{
	char* pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

unsigned int Reverse(unsigned int b) 
{ 
	b = (b & 240) >> 4 | (b & 15) << 4; // Сначала левые четыре бита заменяются правыми
	b = (b & 204) >> 2 | (b & 51) << 2; // Затем соседние пары меняются местами
	b = (b & 170) >> 1 | (b & 85) << 1; // А затем и все соседние отдельные биты 

	return b;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "There are not enough arguments." << endl;
		cout << "Correct entry: flipbyte.exe <enter byte>" << endl;
		return 1;
	}

	bool err = true;
	unsigned int number = StringToInt(argv[1], err);

	if (err) 
	{
		cout << "Argument is not a number" << endl;
		return 1;
	}

	if ((number < 0) || (number > 255)) 
	{
		cout << "Number is less than 0 or greater than 255" << endl;
		return 1;
	}

	cout << Reverse(number) << endl;

    return 0;
}

