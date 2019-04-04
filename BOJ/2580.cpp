#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int d[9][9], r[9][10], c[9][10], m[9][10];
bool flag = false;

int getm(int x,int y)
{
	return x / 3 * 3 + y / 3;
}

void solve(int x, int y)
{
	if (x == 9)
	{
		flag = true;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				printf("%d ", d[i][j]);
			printf("\n");
		}
		return;
	}
	if (y == 9) return solve(x + 1, 0);
	if (d[x][y] != 0) return solve(x, y + 1);
	for (int i = 1; i <= 9; i++)
	{
		if (r[x][i] == 1) continue;
		if (c[y][i] == 1) continue;
		if (m[getm(x, y)][i] == 1) continue;
		d[x][y] = i, r[x][i] = 1, c[y][i] = 1, m[getm(x, y)][i] = 1;
		solve(x, y + 1);
		if (flag) return;
		d[x][y] = 0, r[x][i] = 0, c[y][i] = 0, m[getm(x, y)][i] = 0;
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) scanf("%1d", &d[i][j]);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (d[i][j] == 0) continue;
			int x = d[i][j];
			r[i][x] = 1, c[j][x] = 1, m[getm(i, j)][x] = 1;
		}
	solve(0, 0);
	return 0;
}