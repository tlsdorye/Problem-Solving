#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<int>> d;
vector <vector<bool>> visit;
vector<int> ans;
int n;

bool bdc(int x,int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

void solve(int a,int b)
{
	if (visit[a][b]) return;
	visit[a][b] = true;
	if (d[a][b] == 0) return;
	int x, y;
	queue<P> que;
	que.push(make_pair(a, b));
	ans.push_back(0);
	while (!que.empty())
	{
		P p = que.front();
		que.pop();
		x = p.first, y = p.second;
		if (d[x][y] == 1)
		{
			ans.back()++;
			for (int i = 0; i < 4; i++)
			{
				x += dx[i], y += dy[i];
				if (bdc(x, y) && !visit[x][y])
				{
					visit[x][y] = true;
					que.push(make_pair(x, y));
				}
				x -= dx[i], y -= dy[i];
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	d.resize(n, vector<int>());
	visit.resize(n, vector<bool>());
	for (int i = 0; i < n; i++)
	{
		d[i].resize(n, 0);
		visit[i].resize(n, false);
		for (int j = 0; j < n; j++)
			scanf("%1d", &d[i][j]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visit[i][j]) solve(i, j);
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);
	return 0;
}