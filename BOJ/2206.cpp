#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> T;

int N, M;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visit[1001][1001][2];
vector<vector<int>> map;
queue<T> que;

bool Check(int x, int y)
{
	return 1 <= x && x <= N && 1 <= y && y <= M;
}

int BFS()
{
	que.push({ 1, 1, 0 });
	visit[1][1][0] = true;

	int level = 1;
	int qsize = 0;
	while (!que.empty())
	{
		qsize = que.size();
		for (int i = 0; i < qsize; i++)
		{
			T t = que.front();
			que.pop();
			if (get<0>(t) == N && get<1>(t) == M) return level;
			for (int j = 0; j < 4; j++)
			{
				int nx = get<0>(t) + dx[j];
				int ny = get<1>(t) + dy[j];
				int ct = get<2>(t);
				if (!Check(nx, ny)) continue;
				int nt = ct + map[nx][ny];
				if (nt >= 2) continue;
				if (visit[nx][ny][nt]) continue;
				visit[nx][ny][nt] = true;
				que.push({ nx, ny, nt });
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
	map.resize(N + 1, vector<int>());
	for (int i = 1; i <= N; i++) {
		map[i].resize(M + 1, 0);
		for (int j = 1; j <= M; j++)
			scanf("%1d", &map[i][j]);
	}
	cout << BFS();
}