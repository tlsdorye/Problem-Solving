#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, R, C, D;

int board[51][51];
bool clean[51][51];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void print()
{
	printf("------------------------------\n");
	for (int i = 0; i < N; i++, printf("\n"))
		for (int j = 0; j < M; j++)
		{
			if (clean[i][j]) printf("x ");
			else printf("%d ", board[i][j]);
		}
}

int solve()
{
	int ret = 0;
	clean[R][C] = true, ret++;	// 자신의 방 청소
	int curr_x = R, curr_y = C;
	int next_x, next_y;
	int rot = D;
	while (true)
	{
		bool flag = false;
		for (int i = 0; i < 4; i++)
		{
			if (flag) break;
			next_x = curr_x + dx[rot], next_y = curr_y + dy[rot];
			if (!clean[next_x][next_y] && board[next_x][next_y] == 0)
			{
				ret++;
				clean[next_x][next_y] = true;
				curr_x = next_x, curr_y = next_y;
				flag = true;
			}
			rot += 3;
			rot %= 4;
		}
		if (!flag)
		{
			next_x = curr_x + dx[(rot + 3) % 4], next_y = curr_y + dy[(rot + 3) % 4];
			if (board[next_x][next_y] == 0) curr_x = next_x, curr_y = next_y;
			else return ret;
		}
	}
}

int main()
{
	cin >> N >> M >> R >> C >> D;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &board[i][j]);
	cout << solve();
}