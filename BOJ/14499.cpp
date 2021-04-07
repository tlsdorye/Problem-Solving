#include <iostream>
using namespace std;

int N, M, K;
int curr_x, curr_y;

int board[21][21];

int side[6] = { 0, 0, 0, 0, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int dm[4][3] = {
	{ 4, 5, 2 }, //동: top -> east -> bot -> west -> top
	{ 2, 5, 4 }, //서: top -> west -> bot -> east -> top
	{ 1, 5, 3 }, //북: top -> nor -> bot -> sou -> top
	{ 3, 5, 1 }, //남: top -> sou -> bot -> nor -> top
};

bool check(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < M;
}

void solve(int x, int y)
{
	if (board[x][y] == 0) board[x][y] = side[5];
	else
	{
		side[5] = board[x][y];
		board[x][y] = 0;
	}
	printf("%d\n", side[0]);
}

void move(int dr)
{
	if (!check(curr_x + dx[dr], curr_y + dy[dr])) return;
	curr_x += dx[dr], curr_y += dy[dr];
	
	int temp = side[0];
	side[0] = side[dm[dr][0]];
	side[dm[dr][0]] = side[dm[dr][1]];
	side[dm[dr][1]] = side[dm[dr][2]];
	side[dm[dr][2]] = temp;
	solve(curr_x, curr_y);
}

int main()
{
	cin >> N >> M >> curr_x >> curr_y >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &board[i][j]);

	int dr;
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &dr);
		move(dr-1);
	}
}