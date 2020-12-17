#include <cstdio>
#include <cstdlib>

int main()
{
	unsigned long long n(0);
	scanf("%llu", &n);
	char* data((char*)malloc(256));
	for (unsigned long long c0(0); c0 < n; ++c0)
	{
		scanf("%s", data);
		unsigned long long c1(0);
		char c(data[c1]);
		while (c)
		{
			switch (c)
			{
			case 'A':data[c1] = 'T'; break;
			case 'T':data[c1] = 'A'; break;
			case 'G':data[c1] = 'C'; break;
			case 'C':data[c1] = 'G'; break;
			}
			c=data[++c1];
		}
		printf("%s\n", data);
	}
	free(data);
}