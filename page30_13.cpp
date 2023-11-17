#include <iostream>
#include <cmath>

int main()
{
	return 0;
}

bool IsPrimeNumber(unsigned a)
{
	unsigned sqt = sqrt(a);
	for (unsigned i = 2; i <= sqt; ++i)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}