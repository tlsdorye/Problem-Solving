#include <stdio.h>
#include <algorithm>
#define INF 2147483647
using namespace std;

int d[2002][2002];
int a[2002];
int n, ans = INF;

int abs(int x, int y)
{
	if (x == 0 || y == 0) return 0;
	return a[x] < a[y] ? a[y] - a[x] : a[x] - a[y];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) d[i][j] = INF;
	d[0][0] = 0;
	d[1][2] = 0;
	d[2][1] = 0;
	for (int i = 1; i <= n; i++)
	{
		d[0][i] = d[0][i - 1] + abs(i,i-1);
		d[i][0] = d[i - 1][0] + abs(i,i-1);
	}

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
		{
			if (i < j)
			{
				d[i][j + 1] = min(d[i][j + 1], d[i][j] + abs(j+1,j));
				d[j + 1][j] = min(d[j + 1][j], d[i][j] + abs(j+1,i));
			}
			else if (i > j)
			{
				d[i + 1][j] = min(d[i + 1][j], d[i][j] + abs(i+1,i));
				d[i][i + 1] = min(d[i][i + 1], d[i][j] + abs(i+1,j));
			}
			if (ans > d[i][n]) ans = d[i][n];
		}
	printf("%d", ans);
	return 0;
}