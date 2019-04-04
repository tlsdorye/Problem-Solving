#include <cstdio>
#include <stdlib.h>
#define H_MAX 52
#define V_MAX 52

int x[4] = { 1,0,-1,0 };
int y[4] = { 0,1,0 ,-1};
int b[H_MAX][V_MAX];

void dfs(int i,int j)
{
	b[i][j] = 0;
	for (int k = 0; k < 4; k++)
		if (b[i + x[k]][j + y[k]]) dfs(i + x[k], j + y[k]);
}

int dfs_all(int m,int n)
{
	int component = 0;
	for(int i=1;i<=m;i++)
		for (int j = 1; j <= n; j++)
			if (b[i][j]) dfs(i, j), component++;
	return component;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m, n, k,x1,y1;
		scanf("%d %d %d", &m, &n, &k);

		for (int i = 0; i < H_MAX; i++)
			for (int j = 0; j < V_MAX; j++) b[i][j] = 0;

		for (int i = 0; i < k; i++)
		{
			scanf("%d %d", &x1, &y1);
			b[x1+1][y1+1] = 1;
		}
		int component = dfs_all(m, n);
		printf("%d\n", component);
	}
	return 0;
}