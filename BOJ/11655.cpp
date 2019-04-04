#include <stdio.h>
#include <cstring>

int main()
{
	char c;
	for (;~scanf("%c", &c);)
	{
		if ('A' <= c && c <= 'Z')
		{
			if (c <= 'M')c += 13;
			else c -= 13;
		}
		else if ('a' <= c && c <= 'z')
		{
			if (c <= 'm')c += 13;
			else c -= 13;
		}
		else if (c==' ');
		printf("%c", c);
	}
	return 0;
}
