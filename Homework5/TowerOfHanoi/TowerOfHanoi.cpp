#include <cstdio>

void put(unsigned long long n, char source, char destination, char blank)
{
	if (n == 1)printf("%c->%c\n", source, destination);
	else
	{
		put(n - 1, source, blank, destination);
		printf("%c->%c\n", source, destination);
		put(n - 1, blank, destination, source);
	}
}


int main()
{
	unsigned long long n(1);
	scanf("%llu", &n);
	put(n, 'A', 'C', 'B');
}