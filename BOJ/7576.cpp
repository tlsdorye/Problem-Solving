#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#include <map>
#define INF 987654321
typedef long long ll;
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;

bool bc(int x, int y)
{
	return 0 <= x && x < m && 0 <= y && y < n;
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> d(m, vector<int>(n, 0));
	queue<pair<int, int>> que;
	bool flag = true;
	for(int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> d[i][j];
			if (d[i][j] == 1) que.push(make_pair(i, j));
			else flag = false;
		}
	if (flag)
	{
		cout << 0;
		return 0;
	}
	int level = que.size(), ans = 0;
	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (bc(a, b) && d[a][b] == 0) d[a][b] = d[x][y] + 1, que.push(make_pair(a, b));
		}
		if (--level	 == 0) ans++, level = que.size();
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (d[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
	cout << ans - 1;
}