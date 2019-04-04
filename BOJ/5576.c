#include <stdio.h>

int main()
{
	int a[10] = { 0 };
	int b[10] = { 0 };
	int i, k,m,n;
	for (i = 0; i < 10; i++) scanf("%d", a + i);
	for (i = 0; i < 10; i++) scanf("%d", b + i);

	for (i = 0; i < 9; i++)
	{
		for (k = 0; k < 9; k++)
		{
			if (a[k] > a[k + 1])
			{
				m = a[k + 1]; a[k + 1] = a[k]; a[k] = m;
			}
			if (b[k] > b[k + 1])
			{
				n = b[k + 1]; b[k + 1] = b[k]; b[k] = n;
			}
		}
	}
	int sum1 = 0, sum2 = 0;
	sum1 = a[7] + a[8] + a[9];
	sum2 = b[7] + b[8] + b[9];
	printf("%d %d", sum1, sum2);
	return 0;
}