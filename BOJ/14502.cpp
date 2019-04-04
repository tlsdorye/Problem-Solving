#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int N, M, ans = 0, Wn = 0;
int D[9][9];
bool visit[9][9];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<P> V, E;

bool check(int i, int j)
{
	return 0 <= i && i < N && 0 <= j && j < M;
}

void countAns()
{
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!visit[i][j]) ret++;
	ans = max(ans, ret - Wn);
	memset(visit, 0, sizeof(visit));
}

void bfs()
{
	queue<P> que;
	for (int i = 0; i < V.size(); i++)
	{
		que.push(V[i]);
		visit[V[i].first][V[i].second] = true;
	}
	while (!que.empty())
	{
		P curr = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curr.first + dx[i], ny = curr.second + dy[i];
			if (check(nx, ny) && !visit[nx][ny] && D[nx][ny] != 1)
			{
				visit[nx][ny] = true;
				que.push(make_pair(nx, ny));
			}
		}
	}
	countAns();
}

void solve(int x, int y, int cnt)
{
	if (cnt == 3)
	{
		bfs();
		return;
	}
	if (x == N) return;
	if (y == M)
	{
		solve(x + 1, 0, cnt);
		return;
	}
	if (D[x][y])
	{
		solve(x, y + 1, cnt);
		return;
	}
	D[x][y] = 1;
	solve(x, y + 1, cnt + 1);
	D[x][y] = 0;
	solve(x, y + 1, cnt);

}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> D[i][j];
			if (D[i][j] == 2) V.push_back(make_pair(i, j));
			else if (D[i][j] == 1) Wn++;
		}
	Wn += 3;
	solve(0, 0, 0);
	cout << ans;
}

/*

for (int i = 0; i < E.size(); i++)
for (int j = i + 1; j < E.size(); j++)
for (int k = j + 1; k < E.size(); k++)
{
D[E[i].first][E[i].second] = 1;
D[E[j].first][E[j].second] = 1;
D[E[k].first][E[k].second] = 1;
for (int v = 0; v < V.size(); v++) bfs(V[v]);
countAns();
D[E[i].first][E[i].second] = 0;
D[E[j].first][E[j].second] = 0;
D[E[k].first][E[k].second] = 0;
memset(visit, 0, sizeof(visit));
}
*/