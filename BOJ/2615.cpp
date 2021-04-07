#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int grid[21][21];
int check[21][21][4];
int dx[4] = { 0, 1, 1, 1 };
int dy[4] = { 1, 1, 0, -1 };

bool CheckBD(int x, int y)
{
	return 1 <= x && x <= 19 && 1 <= y && y <= 19;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= 19; j++)
			scanf("%d", &grid[i][j]);

	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= 19; j++)
		{
			if (grid[i][j] == 0) continue;
					
			int color = grid[i][j];
			for (int d = 0; d < 4; d++)
			{
				if (check[i][j][d]) continue;

				int nx = i, ny = j, cnt = 0;
				while (CheckBD(nx, ny))
				{
					if (grid[nx][ny] != color) break;
					nx += dx[d], ny += dy[d], cnt++;
				}

				if (cnt < 5) continue;
				else if (cnt == 5)
				{
					int x = i, y = j;
					if (d == 3) x = nx - dx[d], y = ny - dy[d];
					printf("%d\n%d %d", color, x, y);
					return 0;
				}
				else
				{
					int cx = i, cy = j;
					for (int j = 0; j < cnt; j++)
						check[cx += dx[d]][cy += dy[d]][d] = true;
				}
			}
		}
	printf("0");
}