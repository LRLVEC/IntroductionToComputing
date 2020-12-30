#include <cstdio>
#include <cstdlib>
#include <new>
#include <algorithm>

struct WhiteMouse
{
	unsigned int weight;
	char color[11];
	WhiteMouse()
	{
		scanf("%u%s", &weight, color);
	}
	bool operator<(WhiteMouse const& a)const
	{
		return weight > a.weight;
	}
};

int main()
{
	unsigned int n(0);
	scanf("%u", &n);
	WhiteMouse* mice((WhiteMouse*)malloc(n * sizeof(WhiteMouse)));
	for (unsigned int c0(0); c0 < n; ++c0)
		new(mice + c0)WhiteMouse();
	std::sort(mice, mice + n);
	for (unsigned int c0(0); c0 < n - 1; ++c0)
		printf("%s\n", mice[c0].color);
	printf("%s", mice[n - 1].color);
	free(mice);
}