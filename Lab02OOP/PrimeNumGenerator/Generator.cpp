#include "stdafx.h"
#include "Generator.h"
#include "vector"

std::set<long long> GeneratePrimeNumbersSet(long long maxNum)
{
	std::vector<bool> primeNum(maxNum + 1, true);
	std::set<long long> setOfPrimeNum;
	primeNum[0] = primeNum[1] = false;
	for (long long i = 2; i <= maxNum; i++)
	{
		if (primeNum[i])
		{
			setOfPrimeNum.insert(i);
			for (long long j = i * i; j <= maxNum; j += i)
				primeNum[j] = false;
		}
	}

	return setOfPrimeNum;
}