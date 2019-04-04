#include <stdio.h>	
int main()
{
	int a, b;
	int i, k, j;
	scanf("%d %d", &a, &b);
	int c[5];
		for (i = 0; i < 5; i++) scanf("%d", c + i);

		printf("%d %d %d %d %d", c[0] - a*b, c[1] - a*b, c[2] - a*b, c[3] - a*b, c[4] - a*b);
	return 0;
}