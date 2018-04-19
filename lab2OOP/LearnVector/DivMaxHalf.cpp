#include "stdafx.h"
#include "vector"
#include "DivMaxHalf.h"

void DivMaxHalf(std::vector<double> &arrayOfNum) //4
{
	double maxHalf = *max_element(arrayOfNum.begin(), arrayOfNum.end()) / 2;
	for (auto &num : arrayOfNum)
	{
		num *= maxHalf;
	}
}
