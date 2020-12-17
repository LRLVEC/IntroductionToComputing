#include <cstdio>

int main()
{
	long long a[100];
	unsigned long long num(0);
	scanf("%llu", &num);
	for (unsigned long long c0(0); c0 < num; ++c0)
		scanf("%lld", a + c0);
	long long m0, m1;
	if (a[0] > a[1])
	{
		m0 = a[0];
		m1 = a[1];
	}
	else
	{
		m0 = a[1];
		m1 = a[0];
	}
	for (unsigned long long c0(2); c0 < num; ++c0)
	{
		long long x(a[c0]);
		if (x > m0)
		{
			m1 = m0;
			m0 = x;
		}
		else if (x > m1)
		{
			m1 = x;
		}
	}
	printf("%lld\n%lld", m0, m1);
}