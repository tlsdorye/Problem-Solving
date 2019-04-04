#include <stdio.h>

int main()
{
	int a[3];
	int i, j, k,m;
	for (i = 0; i < 3; i++) scanf("%d", a + i);
	getchar();
	for (i = 0; i < 3; i++)
	{
		for (k = 0; k < 2; k++)
		{
			if (a[k] > a[k + 1])
			{
				m = a[k + 1];
				a[k + 1] = a[k];
				a[k] = m;
			}
		}
	}
	char b;

	for (i = 0; i < 3; i++)
	{
		b = getchar();
		if (b == 65) printf("%d ",a[0]);
		else if (b == 66) printf("%d ",a[1]);
		else if (b == 67) printf("%d ",a[2]);
	}
	

	return 0;
}