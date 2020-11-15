#include <cstdio>
#include <cstdlib>
#include <algorithm>

int main()
{
	unsigned long long n(0), k(0);
	scanf("%llu %llu", &n, &k);
	long long* data((long long*)::malloc(n * sizeof(long long)));
	for (unsigned long long c0(0); c0 < n; ++c0)
		scanf("%lld", data + c0);

	std::sort(data, data + n);

	for (unsigned long long c0(0); c0 < n - 1; ++c0)
	{
		for (unsigned long long c1(n - 1); c1 > c0; --c1)
		{
			if (data[c0] + data[c1] == k)
			{
				::free(data);
				::printf("yes");
				exit(0);
			}
		}
	}
	::free(data);
	::printf("no");
}