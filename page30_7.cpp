#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <memory>
#include <stdlib.h>
#include <cmath>
constexpr unsigned N1 = 10000;
constexpr unsigned N2 = 100;
constexpr unsigned N3 = 100;

void RandomPermutation1(unsigned arr[], unsigned n);
void RandomPermutation2(unsigned arr[], unsigned n);
void RandomPermutation3(unsigned arr[], unsigned n);
inline void swap(unsigned* p1, unsigned* p2);
unsigned N_2(unsigned x, unsigned n);

int main()
{
	unsigned A[N1] = {};
	unsigned B[N2] = {};
	unsigned C[N3] = {};
	unsigned i = 0, j = 0;
	clock_t begin = 0, end = 0;

	j = 0;
	for (unsigned i = 100; i != N1; i += 100)
	{
		if (j++ % 10 == 0)
			std::cout << std::endl;
		begin = clock();
		RandomPermutation1(A, N1);
		end = clock();
		std::cout << 10000*((double)end - (double)begin) / ((long double)i*i/2.0 - i/2.0) << "\t";
	}
	std::cout << std::endl;
	//N_2(i, 2) * 
	return 0;
}

//std::sort(A, A + N, std::less<unsigned>());

/*for (const auto& a : A)
	{
		++i;
		std::cout << a << "\t";
		if (i % 10 == 0)
			std::cout << "\n";
	}
	std::cout << std::endl;*/

void RandomPermutation1(unsigned arr[], unsigned n)
{
	std::default_random_engine e;
	std::uniform_int_distribution<unsigned> u(0, n - 1);
	bool repeat = true;
	unsigned temp = u(e);
	for (unsigned i = 0; i != n; ++i)
	{
		repeat = true;
		while (repeat)
		{
			repeat = false;
			temp = u(e);
			for (unsigned j = 0; j != i; ++j)
			{
				if (temp == arr[j])
				{
					repeat = true;
					break;
				}
			}
		}
		arr[i] = temp;
	}
}

void RandomPermutation2(unsigned arr[], unsigned n)
{
	std::default_random_engine e;
	std::uniform_int_distribution<unsigned> u(0, n - 1);
	unsigned temp = u(e);
	unsigned* const check = (unsigned*)malloc(n * sizeof(unsigned));
	if (check == nullptr)
	{
		exit(1);
		return;
	}
	std::uninitialized_fill_n(check, n, 0);

	for (unsigned i = 0; i != n; ++i)
	{
		while (check[temp] == 1)
			temp = u(e);
		arr[i] = temp;
		check[temp] = 1;
	}
	
	free(check);
	return;
}

void RandomPermutation3(unsigned arr[], unsigned n)
{
	std::default_random_engine e;
	std::uniform_int_distribution<unsigned> u(0, n - 1);

	for (unsigned i = 0; i != n - 1; ++i)
	{
		arr[i] = i + 1;
	}
	arr[n - 1] = 0;

	for (unsigned i = 0; i != n; ++i)
	{
		std::uniform_int_distribution<unsigned> u(0, i);
		swap(&arr[i], &arr[u(e)]);
	}
}

inline void swap(unsigned* p1, unsigned* p2)
{
	if (p1 != p2)
	{
		*p1 = *p2 ^ *p1;
		*p2 = *p1 ^ *p2;
		*p1 = *p1 ^ *p2;
	}
}

unsigned N_2(unsigned x, unsigned n)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return N_2(x * x, n / 2);
	else
		return x * N_2(x * x, n / 2);
}