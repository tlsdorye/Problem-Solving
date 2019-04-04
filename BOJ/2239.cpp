#include <iostream>
using namespace std;

int D[9][9], R[9][10], C[9][10], B[9][10];
bool flag = false;

int getB(int x, int y)
{
	return x / 3 * 3 + y / 3;
}

void solve(int x, int y)
{
	if (x == 9)
	{
		flag = true;
		for (int i = 0; i < 9; i++, printf("\n"))
			for (int j = 0; j < 9; j++) printf("%d", D[i][j]);
		return;
	}
	if (y == 9) return solve(x + 1, 0);
	if (D[x][y] != 0) return solve(x, y + 1);
	for (int i = 1; i <= 9; i++)
	{
		if (R[x][i] == 1) continue;
		if (C[y][i] == 1) continue;
		if (B[getB(x, y)][i] == 1) continue;
		D[x][y] = i, R[x][i] = 1, C[y][i] = 1, B[getB(x, y)][i] = 1;
		solve(x, y + 1);
		if (flag) return;
		D[x][y] = 0, R[x][i] = 0, C[y][i] = 0, B[getB(x, y)][i] = 0;
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) scanf("%1d", &D[i][j]);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (D[i][j] == 0) continue;
			int x = D[i][j];
			R[i][x] = 1, C[j][x] = 1, B[getB(i, j)][x] = 1;
		}
	solve(0, 0);
	return 0;
}