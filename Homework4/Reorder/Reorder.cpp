#include <cstdio>

int main()
{
	unsigned int a[128]{ 0 }, b[128]{ 0 };
	char ca[1024], cb[1024];
	scanf("%s%s", ca, cb);
	unsigned long long pos(0);
	while (ca[pos])a[ca[pos++]]++;
	pos = 0;
	while (cb[pos])b[cb[pos++]]++;
	pos = 0;
	for (; pos < 128; ++pos)
		if (a[pos] != b[pos])
		{
			printf("NO");
			break;
		}
	if (pos == 128)printf("YES");
}