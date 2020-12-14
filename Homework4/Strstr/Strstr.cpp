#include <cstdio>
#include <cstring>
#include <cstdlib>

int main()
{
	char* a((char*)malloc(101));
	char* b((char*)malloc(101));
	scanf("%s", a);
	scanf("%s", b);
	if (strstr(a, b))printf("%s is substring of %s", b, a);
	else if (strstr(b, a))printf("%s is substring of %s", a, b);
	else printf("No substring");
	free(a);
	free(b);
}