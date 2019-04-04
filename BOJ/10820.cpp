#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int a[4] = { 0 };
char s[101];

int main()
{
	int c = 0;
	while (c!=EOF)
	{
		c = getchar();
		if(c=='\n') printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]), fill(a, a + 4, 0);
		else
		{
			if ('a' <= c && c <= 'z') a[0]++;
			else if ('A' <= c && c <= 'Z') a[1]++;
			else if ('0' <= c && c <= '9') a[2]++;
			else if (c == ' ') a[3]++;
		}
	}
	return 0;
}