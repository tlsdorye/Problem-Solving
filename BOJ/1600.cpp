#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

class T
{
public:
	int x, y, k;
	T(int x, int y, int k)
	{
		this->x = x;
		this->y = y;
		this->k = k;
	}
};

int K, N, M, ans = 2e9;
int grid[201][201];
bool visit[201][201][31];
int dx[12] = { 0, 0, 1, -1, -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[12] = { 1, -1, 0, 0, 1, 2, 2, 1, -1, -2, -2, -1 };
queue<T> que;

bool Check(int x, int y)
{
	return 0 <= x && x < M && 0 <= y && y < N;
}

void BFS()
{
	que.push({ 0, 0, 0 });
	visit[0][0][0] = true;

	int level = 0;
	int qsize = 0;
	while (!que.empty())
	{
		qsize = que.size();
		for (int i = 0; i < qsize; i++)
		{
			T cur = que.front();
			que.pop();
			if (cur.x == M - 1 && cur.y == N - 1)
			{
				ans = min(ans, level);
				continue;
			}
			for (int j = 0; j < 12; j++)
			{
				int nx = cur.x + dx[j];
				int ny = cur.y + dy[j];
				int nk = cur.k;
				if (j >= 4) nk++;
				if (!Check(nx, ny)) continue;
				if (visit[nx][ny][nk]) continue;
				if (grid[nx][ny] == 1) continue;
				if (nk > K) continue;
				visit[nx][ny][nk] = true;
				que.push({ nx, ny, nk });
			}
		}
		level++;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> K >> N >> M;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &grid[i][j]);
	if (grid[M - 1][N - 1] == 0) BFS();
	if (ans == 2e9) ans = -1;
	printf("%d", ans);
}