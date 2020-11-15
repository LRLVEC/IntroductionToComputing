#include <cstdio>
#include <cstdlib>

int main()
{
	unsigned long long n(0);
	::scanf("%llu", &n);
	for (unsigned long long c0(0); c0 < n; ++c0)
	{
		unsigned long long length(0);
		scanf("%llu", &length);
		long long p, q;
		scanf("%lld", &p);
		unsigned long long up(1);
		unsigned long long down(1);
		unsigned long long N(0);
		for (unsigned long long c1(1); c1 < length; ++c1)
		{
			scanf("%lld", &q);
			if ((up & (q < p)) || (down & (q > p)))
			{
				if (N++)::printf(" ");
				::printf("%llu", c1 - 1);
			}
			up = q > p;
			down = q < p;
			p = q;
		}
		if (up || down)
		{
			if (N++)::printf(" ");
			::printf("%llu", length - 1);
		}
		::printf("\n");
	}
}