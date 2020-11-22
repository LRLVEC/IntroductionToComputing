#include <cstdio>
#include <cstdlib>

template<class T>void BubbleSort(T* a, unsigned long long length)
{
	bool flag;
	do
	{
		flag = false;
		for (unsigned long long c0(0); c0 < length - 1; ++c0)
		{
			if (a[c0] > a[c0 + 1])
			{
				T tp(a[c0]);
				a[c0] = a[c0 + 1];
				a[c0 + 1] = tp;
				flag = true;
			}
		}
	} while (flag);
}
template<class T>void BubbleSortInverse(T* a, unsigned long long length)
{
	bool flag;
	do
	{
		flag = false;
		for (unsigned long long c0(0); c0 < length - 1; ++c0)
		{
			if (a[c0] < a[c0 + 1])
			{
				T tp(a[c0]);
				a[c0] = a[c0 + 1];
				a[c0 + 1] = tp;
				flag = true;
			}
		}
	} while (flag);
}

int main()
{
	unsigned long long n(10);
	unsigned long long* even((unsigned long long*)malloc(n * sizeof(unsigned long long)));
	unsigned long long* odd((unsigned long long*)malloc(n * sizeof(unsigned long long)));
	unsigned long long numEven(0);
	unsigned long long numOdd(0);
	for (unsigned long long c0(0); c0 < n; ++c0)
	{
		unsigned long long tp;
		scanf("%llu", &tp);
		if (tp & 1)even[numEven++] = tp;
		else odd[numOdd++] = tp;
	}
	BubbleSortInverse(even, numEven);
	BubbleSort(odd, numOdd);
	if (numEven)
	{
		printf("%llu", even[0]);
		for (unsigned long long c0(1); c0 < numEven; ++c0)
			printf(" %llu", even[c0]);
		printf(" ");
	}
	if (numOdd)
	{
		printf("%llu", odd[0]);
		for (unsigned long long c0(1); c0 < numEven; ++c0)
			printf(" %llu", odd[c0]);
	}
	free(even);
	free(odd);
}