#include <cstdio>
#include <cstdlib>

int main()
{
	unsigned long long num(0);
	scanf("%llu", &num);
	while (num)
	{
		long long* a((long long*)malloc(num * sizeof(long long)));
		for (unsigned long long c0(0); c0 < num; ++c0)
			scanf("%lld", a + c0);
		unsigned long long length(1);
		unsigned long long lengthMax(1);
		long long x(*a);
		for (unsigned long long c0(1); c0 < num; ++c0)
		{
			if (a[c0] == x)length++;
			else
			{
				if (length > lengthMax)lengthMax = length;
				x = a[c0];
				length = 1;
			}
		}
		if (length > lengthMax)lengthMax = length;
		printf("%llu\n", lengthMax);
		free(a);
		scanf("%llu", &num);
	}
}