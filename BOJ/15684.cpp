#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H;
bool board[31][11];
int ans = 4;


bool TestBoard(int select_num)
{
	for (int i = 1; i <= N; i++)
	{
		int col = i, row = 1;
		while (row <= H)
		{
			if (board[row][col]) col++;
			else if (board[row][col - 1]) col--;
			row++;
		}
		if (col != i) return false;
	}
	ans = min(ans, select_num);
	return true;
}

bool CheckLine(int a, int b)
{
	if (board[a][b] || board[a][b - 1] || board[a][b + 1]) return false;
	return true;
}

void SelectLine(int idx, int select_num)
{
	if (select_num >= 4 || idx >= (H*(N - 1))) return;
	int x = idx / (N - 1) + 1, y = idx % (N - 1) + 1;

	if (CheckLine(x, y))
	{
		board[x][y] = true;
		TestBoard(select_num);
		SelectLine(idx + 1, select_num + 1);
		board[x][y] = false;
	}
	SelectLine(idx + 1, select_num);
}

int main()
{
	cin >> N >> M >> H;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		board[a][b] = true;
	}
	TestBoard(0);
	SelectLine(0, 1);
	if (ans == 4) ans = -1;
	cout << ans;
}