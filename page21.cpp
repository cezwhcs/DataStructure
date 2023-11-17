#include <iostream>
constexpr size_t N = 10;

int MaxSubsequenceSum2(int arr[], int n);
int MaxSubsequenceSum4(int arr[], int n);

int main()
{
	int A[N] = {0, 1, 2, -5, 3, 4, -1, 5, 9, 10};
	std::cout << MaxSubsequenceSum2(A, N) << std::endl;
	std::cout << MaxSubsequenceSum4(A, N) << std::endl;

	return 0;
}

int MaxSubsequenceSum2(int arr[], int n)
{
	int ThisSum = 0, MaxSum = 0;

	for (int i = 0; i < n; ++i)
	{
		ThisSum = 0;
		for (int j = i; j < n; ++j)
		{
			ThisSum += arr[j];
			if (ThisSum > MaxSum)
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}

int MaxSubsequenceSum4(int arr[], int n)
{
	int ThisSum = 0, MaxSum = 0;
	
	for (int i = 0; i < n; ++i)
	{
		ThisSum += arr[i];
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
		}
		else if (ThisSum < 0)
		{
			ThisSum = 0;
		}
	}

	return MaxSum;
}