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

int main()
{
	unsigned long long n(0);
	scanf("%llu", &n);
	unsigned long long* a((unsigned long long*)malloc(n * sizeof(unsigned long long)));
	for (unsigned long long c0(0); c0 < n; ++c0)
		scanf("%llu", a + c0);
	BubbleSort(a, n);
	for (unsigned long long c0(0); c0 < n - 1; ++c0)
		printf("%llu\n", a[c0]);
	printf("%llu", a[n - 1]);
	free(a);
}