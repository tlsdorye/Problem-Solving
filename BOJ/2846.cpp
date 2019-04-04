#include <stdio.h>
int a[1001] = { 0 };
int d[1001] = { 0 };

int main()
{
	int n, max = 0;;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if (i == 0) {}
		else
		{
			if (a[i] > a[i - 1])
			{
				d[i] = d[i-1] + a[i] - a[i - 1];
			}
			else d[i] = 0;
			if (max < d[i]) max = d[i];
		}
	}
	printf("%d", max);
	return 0;
}