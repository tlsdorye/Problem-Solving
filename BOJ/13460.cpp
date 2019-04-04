#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<P> Ball_point;

int N, M;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

char D[11][11];

Ball_point move(int i, Ball_point p)
{
	Ball_point t = p;
	int ri = t[0].first, rj = t[0].second;
	int bi = t[1].first, bj = t[1].second;
	for (int j = 0; j < 2; j++)
	{
		while (D[ri + dx[i]][rj + dy[i]] != '#')
		{
			if (D[ri][rj] == 'O') break;
			if (D[ri + dx[i]][rj + dy[i]] == 'O')
			{
				ri += dx[i], rj += dy[i];
				break;
			}
			if (ri + dx[i] == bi && rj + dy[i] == bj) break;
			ri += dx[i], rj += dy[i];
		}
		while (D[bi + dx[i]][bj + dy[i]] != '#')
		{
			if (D[bi][bj] == 'O') break;
			if (D[bi + dx[i]][bj + dy[i]] == 'O') 
			{
				bi += dx[i], bj += dy[i];
				break;
			}
			if (bi + dx[i] == ri && bj + dy[i] == rj) break;
			bi += dx[i], bj += dy[i];
		}
	}
	t[0] = make_pair(ri, rj);
	t[1] = make_pair(bi, bj);
	return t;
}

int bfs(Ball_point p)
{
	queue<Ball_point> que;
	que.push(p);
	int size = que.size(), level = 0;
	while (!que.empty())
	{
		Ball_point top = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			Ball_point mp = move(i, top);
			int ri = mp[0].first, rj = mp[0].second;
			int bi = mp[1].first, bj = mp[1].second;
			if (D[ri][rj] == 'O' && D[bi][bj] != 'O') return level + 1;
			if (mp != top && D[bi][bj] != 'O') que.push(mp);
		}
		if (--size == 0) size = que.size(), level++;
		if (level >= 10) return -1;
	}
	return -1;
}


int main()
{

	P R_point;
	P B_point;
	Ball_point p;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> D[i][j];
			if (D[i][j] == 'R') R_point = make_pair(i, j);
			else if (D[i][j] == 'B') B_point = make_pair(i, j);
		}

	p.push_back(R_point);
	p.push_back(B_point);
	cout << bfs(p);
}