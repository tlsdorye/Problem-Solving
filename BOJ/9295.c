#include <stdio.h>	
int main()
{
	int t;
	int i;
	int k = 1;
	scanf("%d", &t);
	int* a = (int*)malloc(sizeof(int)*2*t);
	for (i = 0; i <2*t; i++) scanf("%d", a + i);

	for (i = 0; i < 2*t; i = i + 2,k++) 
	{
			printf("Case %d: %d", k, a[i] + a[i + 1]);
			if (i != 2 * t - 1) printf("\n");
	}
	return 0;
}