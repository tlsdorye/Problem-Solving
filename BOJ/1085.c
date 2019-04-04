#include <stdio.h>

int main()
{
	int x, y, w, h;
	int i;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int a[4] = { x,y,w - x,h - y };
	int min = 1000;
	for (i = 0; i < 4; i++)
	{
		if (min > a[i]) { min = a[i]; }
	}
	printf("%d", min);

	return 0;
}