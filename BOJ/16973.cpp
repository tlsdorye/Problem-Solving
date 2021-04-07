#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

typedef pair<int, int> P;

int N, M, H, W;
int Sx, Sy, Fx, Fy;

int grid[1001][1001];
bool visit[1001][1001];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<P> pos_wall;
queue<P> que;

void FillVisit(int fx, int fy) {
	int sx = (fx - H + 1);
	int sy = (fy - W + 1);

	if (sx < 1) sx = 1;
	if (sy < 1) sy = 1;

	for (int i = sx; i <= fx; i++)
	{
		visit[i][sy] = true;
		visit[i][fy] = true;
	}
	for (int j = sy; j <= fy; j++)
	{
		visit[sx][j] = true;
		visit[fx][j] = true;
	}
}

bool CheckBoundary(int x, int y)
{
	return 1 <= x && x <= (N - H + 1) && 1 <= y && y <= (M - W + 1);
}

int BFS()
{
	que.push({ Sx, Sy });
	visit[Sx][Sy] = true;

	int level = 0;
	int qsize = 0;
	while (!que.empty())
	{
		qsize = que.size();
		for (int i = 0; i < qsize; i++)
		{
			P cur = que.front();
			que.pop();
			if (cur.first == Fx && cur.second == Fy) return level;
			for (int j = 0; j < 4; j++)
			{
				int nx = cur.first + dx[j];
				int ny = cur.second + dy[j];
				if (!CheckBoundary(nx, ny)) continue;
				if (visit[nx][ny]) continue;
				que.push({ nx, ny });
				visit[nx][ny] = true;
			}
		}
		level++;
	}
	return -1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &grid[i][j]);
			if (grid[i][j] == 1)
				pos_wall.push_back({ i, j });
		}
	cin >> H >> W >> Sx >> Sy >> Fx >> Fy;

	for (P p : pos_wall) FillVisit(p.first, p.second);

	//for (int i = 1; i <= N; i++, printf("\n"))
	//	for (int j = 1; j <= M; j++)
	//		printf("%2d", visit[i][j]);
	//printf("\n");

	printf("%d", BFS());
}