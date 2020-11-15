#include <cstdio>
#include <cstdlib>
#include <algorithm>

struct Section
{
	unsigned long long a;
	unsigned long long b;
	bool operator<(Section const& y)const
	{
		return a < y.a;
	}
};

int main()
{
	unsigned long long L(0), M(0);
	::scanf("%llu %llu", &L, &M);
	size_t length(M * sizeof(Section));
	Section* data((Section*)::malloc(length));
	for (unsigned long long c0(0); c0 < M; ++c0)
		scanf("%llu %llu", &data[c0].a, &data[c0].b);

	std::sort(data, data + M);

	unsigned long long beginning(data[0].a), ending(data[0].b);
	unsigned long long blankLength(beginning);
	for (unsigned long long c0(1); c0 < M; ++c0)
	{
		if (data[c0].a <= ending + 1)
		{
			ending = ending > data[c0].b ? ending : data[c0].b;
		}
		else
		{
			blankLength += data[c0].a - ending - 1;;
			beginning = data[c0].a;
			ending = data[c0].b;
		}
	}
	blankLength += L - ending;
	::printf("%llu", blankLength);
}