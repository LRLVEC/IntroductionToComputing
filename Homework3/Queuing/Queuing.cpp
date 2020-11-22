#include <cstdio>
#include <cstdlib>

struct Item
{
	unsigned long long time;
	unsigned long long pos;
	bool operator>(Item const& a)
	{
		return time > a.time;
	}
};

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
	Item* a((Item*)malloc(n * sizeof(Item)));
	unsigned long long total(0);
	for (unsigned long long c0(0); c0 < n; ++c0)
	{
		scanf("%llu", &a[c0].time);
		a[c0].pos = c0;
	}
	BubbleSort(a, n);
	for (unsigned long long c0(0); c0 < n - 1; ++c0)
	{
		printf("%llu ", a[c0].pos + 1);
		total += (n - c0 - 1) * a[c0].time;
	}
	printf("%llu\n", a[n - 1].pos + 1);
	printf("%.2f", double(total) / n);
	free(a);
}