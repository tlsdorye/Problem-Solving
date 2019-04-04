#include <stdio.h>

int main()
{
	int i,j;
	for (i = 0; i < 1;)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) break;
		printf("%d %d / %d\n", a / b, a - (a / b)*b, b);
		
	}
	return 0;
}