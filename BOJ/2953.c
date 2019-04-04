#include <stdio.h>
int main()
{
	int a[20] = { 0 };
	int i, k, j;
	for (i = 0; i < 20; i++) scanf("%d", a + i);
	int max = 0, check = 0, sum[5] = { 0 };
	for (i = 0; i < 20; i++)
	{
			sum[i/4] = sum[i/4] + a[i]; 
			if (max < sum[i/4]){
				max = sum[i/4];
				check = i;
		}
	}
	printf("%d %d",check/4 + 1 ,max );
	return 0;
}