#include "stdafx.h"
#include "vector"
#include "iostream"
#include "algorithm"
#include "cmath"
#include "DivMaxHalf.h"

using namespace std;

vector<double> GetVector()
{
	vector<double> arrayOfNum;
	double num;
	while (cin >> num)
	{
		arrayOfNum.push_back(num);
	}

	return arrayOfNum;
}

void AddAverage(vector<double> &arrayOfNum) //1
{
	double sum = 0;
	for (auto num : arrayOfNum)
	{
		if (num > 0)
		{
			sum += round(num * 1000) / 1000;
		}
	}

	double average = sum / arrayOfNum.size();

	for (auto &num : arrayOfNum)
	{
		num += average;
	}
}

void MinElem(vector<double> &arrayOfNum) //2
{
	double minElem = *min_element(arrayOfNum.begin(), arrayOfNum.end());
	for (auto &num : arrayOfNum)
	{
		num *= minElem;
	}

}

void MultAverage(vector<double> &arrayOfNum) //3
{
	double sum = 0;
	for (auto num : arrayOfNum)
	{
		if (static_cast<int>(num) % 2 == 0)
		{
			sum += round(num * 1000) / 1000;
		}
	}

	double average = sum / arrayOfNum.size();

	for (auto &num : arrayOfNum)
	{
		if (static_cast<int>(num) % 3 == 0)
		{
			num *= average;
		}
	}
}
void MultNegativeElemMaxMin(vector<double> &arrayOfNum) //5
{
	double minElem = *min_element(arrayOfNum.begin(), arrayOfNum.end());
	double maxElem = *max_element(arrayOfNum.begin(), arrayOfNum.end());
	double multMinMaxElem = minElem * maxElem;

	for (auto &num : arrayOfNum)
	{
		if (num < 0) {
			num *= multMinMaxElem;
		}
	}
}

void MultMaxDivMin(vector<double> &arrayOfNum) //6
{
	double minElem = *min_element(arrayOfNum.begin(), arrayOfNum.end());
	double maxElem = *max_element(arrayOfNum.begin(), arrayOfNum.end());

	for (auto &num : arrayOfNum)
	{
		num *= maxElem;
		num /= minElem;
	}
}

void SortVector(vector<double> &arrayOfNum)
{
	sort(arrayOfNum.begin(), arrayOfNum.end());
}

void PrintVector(vector<double> &arrayOfNum)
{
	for (auto num : arrayOfNum)
	{
		cout << num << " ";
	}
	cout << endl;
}



int main()
{
	vector<double> arrayOfNum = GetVector();
	PrintVector(arrayOfNum);
	DivMaxHalf(arrayOfNum);
	PrintVector(arrayOfNum);

	return 0;
}
