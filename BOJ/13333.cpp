#include <stdio.h>

int d[1001];

int main()
{
	int n, count = 0,ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &d[i]);

	for (int k = 0; k <= n; k++)
	{
		for (int j = 0; j < n; j++)
			if (k <= d[j]) count++;
		if (k <= count && k>=ans) ans = k,count = 0;
		else count = 0;
	}
	printf("%d", ans);

	return 0;
}