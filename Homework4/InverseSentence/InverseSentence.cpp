#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
	char* data((char*)malloc(101));
	scanf("%[^\n]", data);
	unsigned long long len(strlen(data));
	long long pos(len);
	for (;;)
	{
		data[pos--] = 0;
		while (pos >= 0 && data[pos] != ' ')pos--;
		pos++;
		printf("%s", data + pos);
		if (pos--)printf(" ");
		else break;
	}
	free(data);
}