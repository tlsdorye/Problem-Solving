#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int N, M;
int D[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool check(P p)
{
	int x = p.first;
	int y = p.second;
	return 0 <= x && x < N && 0 <= y && y < M && D[x][y] == 1;
}

int solve(P p)
{
	int level = 0;
	queue<P> que;
	que.push(p);
	D[p.first][p.second] = 0;
	while (!que.empty())
	{
		int qSize = que.size();
		for (int i = 0; i < qSize; i++)
		{
			P cur = que.front();
			if (cur.first == N - 1 && cur.second == M - 1) return level;
			que.pop();
			for (int j = 0; j < 4; j++)
			{
				P next = make_pair(cur.first + dx[j], cur.second + dy[j]);
				if (check(next)) D[next.first][next.second] = 0, que.push(next);
			}
		}
		level++;
	}
	return level;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%1d", &D[i][j]);
	cout << solve(make_pair(0, 0)) + 1;
}