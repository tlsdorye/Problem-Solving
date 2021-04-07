#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int R, C, T;
int grid[51][51];
vector<P> purifier_pos;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool check(int x, int y)
{
	return 0 <= x && x < R && 0 <= y && y < C;
}

void Spread()
{
	int next_grid[51][51] = { 0 };

	for (int x = 0; x < R; x++)
		for (int y = 0; y < C; y++)
		{
			if (grid[x][y] == -1) next_grid[x][y] = -1;
			else if (grid[x][y] == 0) continue;
			else
			{
				int count = 0;
				for (int d = 0; d < 4; d++)
				{
					int nx = x + dx[d], ny = y + dy[d];

					if (!check(nx, ny)) continue;
					if (grid[nx][ny] == -1) continue;
					next_grid[nx][ny] += grid[x][y] / 5;
					count++;
				}
				next_grid[x][y] += grid[x][y] - (grid[x][y] / 5) * count;
			}
		}

	for (int x = 0; x < R; x++)
		for (int y = 0; y < C; y++)
			grid[x][y] = next_grid[x][y];
}

void WorkPurifier(int idx, int step)
{
	int d = 0;
	int cx = purifier_pos[idx].first, cy = purifier_pos[idx].second;
	int nx = cx + dx[d], ny = cy + dy[d];
	int prev_val = 0, next_val = 0;
	while (grid[nx][ny] != -1)
	{
		next_val = grid[nx][ny];
		grid[nx][ny] = prev_val;
		prev_val = next_val;

		cx = nx, cy = ny;
		nx = cx + dx[d], ny = cy + dy[d];
		if (!check(nx, ny))
		{
			d = (d + step) % 4;
			nx = cx + dx[d], ny = cy + dy[d];
		}
	}
}

int GetDust()
{
	int ret = 2;
	for (int x = 0; x < R; x++)
		for (int y = 0; y < C; y++)
			ret += grid[x][y];
	return ret;
}

int main()
{
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == -1) purifier_pos.push_back({ i, j });
		}

	while (T--)
	{
		Spread();
		WorkPurifier(0, 3);
		WorkPurifier(1, 5);
	}
	cout << GetDust();
}