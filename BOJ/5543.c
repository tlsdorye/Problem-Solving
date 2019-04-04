#include <stdio.h>

int main()
{
	int a[3];
	int b[2];
	int i, k;
	scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &b[0], &b[1]);
	int min1 = 2000;
	int min2 = 2000;
	for (i = 0; i < 3; i++)
	{
		if (min1 > a[i]) min1 = a[i];
	}
	for (i = 0; i < 2; i++)
	{
		if (min2 > b[i]) min2 = b[i];
	}
	printf("%d", min1 + min2 - 50);
	return 0;
}