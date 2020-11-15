#include <cstdio>
#include <cstdlib>

int main()
{
	unsigned long long n(0), m(0);
	::scanf("%llu", &n);
	unsigned long long* data((unsigned long long*)::malloc(n * sizeof(unsigned long long)));
	for (unsigned long long c0(0); c0 < n; ++c0)
		scanf("%llu", data + c0);
	::scanf("%llu", &m);
	for (unsigned long long c0(0); c0 < n; ++c0)
	{
		if (data[c0] % m == 0 || data[c0] / 10 == m || data[c0] % 10 == m)
			::printf("%llu\n", data[c0]);
	}
	::free(data);
}