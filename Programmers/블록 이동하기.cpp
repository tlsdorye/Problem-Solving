#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
typedef pair<int, int> P;

int N;
set<set<P>> visit;
vector<vector<int>> map;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool checkBoundary(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < N;
}

int solution(vector<vector<int>> board) {
	N = board.size();
	map = board;
	int answer = 0;

	set<P> start;
	start.insert({ 0, 0 });
	start.insert({ 0, 1 });
	visit.insert(start);

	queue<set<P>> que;
	que.push(start);
	while (!que.empty())
	{
		int qsize = que.size();
		for (int j = 0; j < qsize; j++)
		{
			set<P> curr = que.front();
			que.pop();
			for (P p : curr)
			{
				if (p.first == N - 1 && p.second == N - 1)
					return answer;
			}

			for (int i = 0; i < 4; i++)
			{
				int nx = curr.begin()->first + dx[i];
				int ny = curr.begin()->second + dy[i];
				int na = (++curr.begin())->first + dx[i];
				int nb = (++curr.begin())->second + dy[i];

				//if (nx == na && i >= 2) continue;
				//if (ny == nb && i <= 1) continue;
				if (!checkBoundary(nx, ny)) continue;
				if (!checkBoundary(na, nb)) continue;
				if (map[nx][ny] == 1) continue;
				if (map[na][nb] == 1) continue;
				set<P> next = { {nx, ny}, {na, nb} };
				if (visit.find(next) != visit.end()) continue;
				visit.insert(next);
				que.push(next);
			}

			int x = curr.begin()->first;
			int y = curr.begin()->second;
			int a = (++curr.begin())->first;
			int b = (++curr.begin())->second;
			if (x == a)
			{
				{
					if (a - 1 >= 0 && b - 1 >= 0 && map[a - 1][b] == 0 && map[a - 1][b - 1] == 0)
					{
						set<P> next = { {x, y}, {a - 1, b - 1} };
						if (visit.find(next) == visit.end()) visit.insert(next), que.push(next);
					}
					if (a + 1 < N && b - 1 >= 0 && map[a + 1][b] == 0 && map[a + 1][b - 1] == 0)
					{
						set<P> next = { {x, y}, {a + 1,b - 1} };
						if (visit.find(next) == visit.end()) visit.insert(next), que.push(next);
					}
				}
				{
					if (x - 1 >= 0 && y + 1 < N && map[x - 1][y] == 0 && map[x - 1][y + 1] == 0)
					{
						set<P> next = { {x - 1, y + 1}, {a, b} };
						if (visit.find(next) == visit.end()) visit.insert(next), que.push(next);
					}
					if (x + 1 < N && y + 1 < N && map[x + 1][y] == 0 && map[x + 1][y + 1] == 0)
					{
						set<P> next = { {x + 1, y + 1}, {a, b} };
						if (visit.find(next) == visit.end()) visit.insert(next), que.push(next);
					}
				}
			}
			else if (y == b)
			{
				{
					if (x + 1 < N && y - 1 >= 0 && map[x][y - 1] == 0 && map[x + 1][y - 1] == 0)
					{
						set<P> next = { {x + 1, y - 1}, {a, b} };
						if (visit.find(next) == visit.end()) visit.insert(next), que.push(next);
					}
					if (x + 1 < N && y + 1 < N && map[x][y + 1] == 0 && map[x + 1][y + 1] == 0)
					{
						set<P> next = { {x + 1, y + 1}, {a, b} };
						if (visit.find(next) == visit.end()) visit.insert(next), que.push(next);
					}
				}
				{
					if (a - 1 >= 0 && b - 1 >= 0 && map[a][b - 1] == 0 && map[a - 1][b - 1] == 0)
					{
						set<P> next = { {x, y}, {a - 1, b - 1} };
						if (visit.find(next) == visit.end()) visit.insert(next), que.push(next);
					}
					if (a - 1 >= 0 && b + 1 < N && map[a][b + 1] == 0 && map[a - 1][b + 1] == 0)
					{
						set<P> next = { {x, y}, {a - 1, b + 1} };
						if (visit.find(next) == visit.end()) visit.insert(next), que.push(next);
					}
				}
			}
		}
		answer++;
	}

	return answer;
}