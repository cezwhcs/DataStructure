#include <iostream>

long long pow(long long x, unsigned n);

int main()
{
	std::cout << pow((long)8, (unsigned)1);

	return 0;
}

long long pow(long long x, unsigned n)
{
	const unsigned tail = 1;
	const unsigned head = 0x80000000;
	unsigned n1 = n;
	unsigned bitwidth = sizeof(unsigned) * 8;
	long long ret = 1, temp = x;
	
	while (!(head & n1) && !bitwidth)
	{
		n1 <<= 1;
		--bitwidth;
	}

	for (n1 = n; bitwidth != 0; --bitwidth)
	{
		if (n1 & tail)
			ret *= temp;
		temp *= temp;
		n1 >>= 1;
	}

	return ret;
}