#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
	char* data((char*)malloc(81));
	scanf("%[^\n]", data);
	unsigned long long len(strlen(data));
	unsigned int delta('A' - 'a');
	if (*data >= 'a' && *data <= 'z')
		*data += delta;
	for (unsigned long long c0(1); c0 < len; ++c0)
	{
		char c(data[c0 - 1]);
		if (c == ' ' || c == '\t' || c == '\r')
		{
			c = data[c0];
			if (c >= 'a' && c <= 'z')
				data[c0] += delta;
		}
	}
	printf("%s", data);
	free(data);
}