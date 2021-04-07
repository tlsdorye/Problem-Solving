#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> P;


int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int ans = -1;

void print(vector<vector<P>> &grid)
{
	for (int i = 0; i < 4; i++, printf("\n"))
		for (int j = 0; j < 4; j++)
			printf("[%2d %2d], ", grid[i][j].first, grid[i][j].second);
	printf("\n");
}

bool bdcheck(int x, int y)
{
	return 0 <= x && x < 4 && 0 <= y && y < 4;
}

void FishMove(vector<vector<P>> &grid, int sx, int sy)
{
	vector<P> indexer(17, { -1, -1 });
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			int idx = grid[i][j].first;
			if (idx < 0) continue;
			indexer[idx].first = i;
			indexer[idx].second = j;
		}
	for (int i = 1; i <= 16; i++)
	{
		int cx = indexer[i].first;
		int cy = indexer[i].second;
		if (!bdcheck(cx, cy)) continue;
		int cd = grid[cx][cy].second;

		for (int j = 0; j < 8; j++)
		{
			int nd = (cd + j) % 8;
			int nx = cx + dx[nd];
			int ny = cy + dy[nd];
			if (!bdcheck(nx, ny) || (nx == sx && ny == sy)) continue;
			else
			{
				int swap_idx = grid[nx][ny].first;
				swap(indexer[i], indexer[swap_idx]);
				grid[cx][cy].second = nd;
				swap(grid[cx][cy], grid[nx][ny]);
				break;
			}
		}
	}
}

void solve(int sx, int sy, int sd, int feed, vector<vector<P>> grid)
{
	if (ans < feed) ans = feed;
	FishMove(grid, sx, sy);

	int nx = sx, ny = sy;
	while (bdcheck(nx += dx[sd], ny += dy[sd]))
	{
		if (grid[nx][ny].first == 0) continue;
		int fish_idx = grid[nx][ny].first;
		int fish_dir = grid[nx][ny].second;
		grid[nx][ny].first = -1;
		grid[sx][sy].first = 0;
		grid[sx][sy].second = -1;
		solve(nx, ny, fish_dir, feed + fish_idx, grid);
		grid[sx][sy].first = -1;
		grid[sx][sy].second = sd;
		grid[nx][ny].first = fish_idx;
	}
}

int main()
{
	vector<vector<P>> grid(4, vector<P>(4, { 0, -1 }));
	int a, b;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			cin >> a >> b;
			grid[i][j].first = a;
			grid[i][j].second = b - 1;
		}
	int fish_idx = grid[0][0].first;
	int fish_dir = grid[0][0].second;
	grid[0][0].first = -1;
	solve(0, 0, fish_dir, fish_idx, grid);
	printf("%d", ans);
}