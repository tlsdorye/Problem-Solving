#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;

char D[101][101];
bool visit[101][101];
int ans[2];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N;

bool check(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < N;
}

void bfs(int u, int v)
{
	queue<P> que;
	que.push(make_pair(u, v));
	visit[u][v] = true;
	while (!que.empty())
	{
		P curr = que.front();
		int x = curr.first, y = curr.second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (!visit[nx][ny] && check(nx, ny) && D[x][y] == D[nx][ny])
			{
				visit[nx][ny] = true;
				que.push(make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> D[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visit[i][j])
			{
				ans[0]++;
				bfs(i, j);
			}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (D[i][j] == 'G') D[i][j] = 'R';
			visit[i][j] = false;
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visit[i][j])
			{
				ans[1]++;
				bfs(i, j);
			}
	cout << ans[0] << "\n" << ans[1];
}
