#include <stdio.h>
#include <algorithm>

using namespace std;

int t, n, ans = 0;
int a[2][100001];
int d[2][100001];

void sticky()
{
	for (int j = 2; j < n; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			if (i == 0)	d[i][j] = max(max(d[i + 1][j - 2], d[i + 1][j - 1]), d[i][j - 2]) + a[i][j];
			else d[i][j] = max(max(d[i - 1][j - 2], d[i][j - 2]), d[i - 1][j - 1]) + a[i][j];
			if (ans < d[i][j]) ans = d[i][j];
		}		
	}
}


int main()
{
	scanf("%d", &t);
	while (t--)
	{
		
		scanf("%d", &n);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
			{
				scanf("%3d", &a[i][j]);
				d[i][j] = -1;
			}
		d[0][0] = a[0][0];
		d[1][0] = a[1][0];
		d[0][1] = a[1][0] + a[0][1];
		d[1][1] = a[0][0] + a[1][1];
		sticky();
		printf("%d\n", ans);
        ans = 0;
	}
	return 0;
}