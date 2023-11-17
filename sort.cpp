#include <iostream>
#include <random>
#include <time.h>
constexpr size_t N = 100;

int main()
{
	size_t A[N] = {};
	size_t B[N] = {};
	size_t C[N] = {};
	int i = 0, j = 0, k = 0;
	
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(0, 10 * N);

	time_t start = clock();

	while (i < N)
	{
		A[i] = distr(eng);
		B[i] = N - i - 1;

		for (j = i - 1; j >= 0; --j)
		{
			if (A[i] > A[j])
			{
				--B[j];
				++B[i];
			}
		}

		++i;
	}

	for (k = 0; k < N; ++k)
	{
		C[B[k]] = A[k];
	}

	time_t end = clock();
	std::cout << "*" << end - start << "*" << std::endl;

	return 0;
}
	
/*for (const auto& i : A)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;

	for (const auto& i : B)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;

	for (const auto& i : C)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;*/
