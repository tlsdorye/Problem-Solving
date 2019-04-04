#include <stdio.h>
#include <string.h>

char p[22];

bool isp()
{
	int l = strlen(p);
	for (int i = 0; i < l/2; i++)
		if (p[i] != p[l - i-1]) return false;
	return true;
}

int main()
{
	scanf("%s", p);
	if (isp()) printf("true");
	else printf("false");
	return 0;
}