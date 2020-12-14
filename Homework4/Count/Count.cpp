#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Data
{
	char c;
	unsigned long long num;
};

int main()
{
	unsigned int table[26];
	unsigned long long n(0);
	char* data((char*)::malloc(1001));
	scanf("%llu", &n);
	Data* results((Data*)::malloc(n * sizeof(Data)));
	for (unsigned long long c0(0); c0 < n; ++c0)
	{
		memset(table, 0, sizeof(table));
		scanf("%s", data);
		unsigned long long p(0);
		while (data[p])++table[data[p++] - 'a'];
		p = 0;
		unsigned long long pos;
		unsigned int num(0);
		do
		{
			if (num < table[p])
				num = table[pos = p];
		} while (++p < 26);
		results[c0].c = 'a' + pos;
		results[c0].num = table[pos];
	}
	for (unsigned long long c0(0); c0 < n; ++c0)
	{
		printf("%c %u", results[c0].c, results[c0].num);
		if (c0 < n - 1)printf("\n\n");
	}
	free(data);
	free(results);
}