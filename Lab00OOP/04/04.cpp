// 04.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("Program calculates sum of its command line arguments.\n");
		return 0;
	}

	double result = 0;
	int f_num = 0;
	int s_num = 0;

	for (int i = 1; i < argc; ++i)
	{
		bool err;
		double param_one = StringToDouble(argv[i], err);
		if (!err) {
			if (argv[i - 1] == "+") {

			}
			else if (argv[i - 1] == "-") {

			}
			else if (argv[i - 1] == "*") {

			}
			else if (argv[i - 1] == "/") {

			}
		}

	}

	return 0;
}
