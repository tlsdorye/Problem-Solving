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

int n, m;
vector<vector<int>> d;

int solve(int x,int y)
{
	int size = 1;
	for (int i = 1; (x + i < n) && (y + i < m); i++)
	{
		if (d[x][y] == d[x + i][y] && d[x][y] == d[x][y + i] && d[x][y] == d[x + i][y + i])
			if (size < (i + 1)*(i + 1)) size = (i + 1)*(i + 1);
	}
	return size;
}

int main()
{
	scanf("%d %d", &n, &m);
	d.resize(n, vector<int>());
	for (int i = 0; i < n; i++)
	{
		d[i].resize(m, 0);
		for (int j = 0; j < m; j++)
			scanf("%1d", &d[i][j]);
	}
	int ans = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int x = solve(i, j);
			if (ans < x) ans = x;
		}
	cout << ans;
}