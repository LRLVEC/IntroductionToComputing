#include <cstdio>

unsigned long long Foo(unsigned long long a, unsigned long long b)
{
	if (a == 0 || b == 1)return 1;
	if (b > a) return Foo(a, a);
	else return Foo(a, b - 1) + Foo(a - b, b);
}

int main()
{
	unsigned long long n(0);
	scanf("%llu", &n);
	for (unsigned long long c0(0); c0 < n; ++c0)
	{
		unsigned long long a, b;
		scanf("%llu%llu", &a, &b);
		printf("%llu\n", Foo(a, b));
	}
}