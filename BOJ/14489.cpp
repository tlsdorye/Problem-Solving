#include <stdio.h>

int main()
{
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	if (x + y >= 2 * z) printf("%d", x + y - 2 * z);
	else printf("%d", x + y);
	return 0;
}