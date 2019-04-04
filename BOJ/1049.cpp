#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m, x, sr = 1111, check = 0;
	scanf("%d %d", &n, &m);
	int* six = (int*)malloc(sizeof(int)*m * 2);
	int* one = (int*)malloc(sizeof(int)*m * 2);
	int s = 1111, o = 1111;
	for (int i = 0; i < m; i++) scanf("%d %d",&six[i],&one[i]);
	x = n / 6;
	for (int i = 0; i < m; i++)
	{
		if (six[i] < s) s = six[i];
		if (one[i] < o) o = one[i];
	}
	if (o * 6 < s)	sr = o*n;
	else
	{
		if (x == 0)
		{
			if (s < sr) sr = s;
			if (o*n < sr) sr = o*n;
		}
		else
		{
			if (s < o*(n - x * 6)) sr = s + s*x;
			else sr = o*(n - x * 6) + s*x;
		}
	}
	printf("%d", sr);
	return 0;
}
