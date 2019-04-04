#include <iostream>
#include <vector>
#include <list>
#include <utility>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, K, L;
int board[101][101];
list<pair<int, int>> snake_pos;
vector<pair<int, char>> snake_info;

bool check(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < N;
}

bool istail(int x, int y)
{
	pair<int, int> tail = snake_pos.back();
	return tail.first == x && tail.second == y;
}

void print_board(int time)
{
	cout << time << endl;
	for (int i = 0; i < N; i++, printf("\n"))
		for (int j = 0; j < N; j++) printf("%d ", board[i][j]);
	printf("-------------------------\n");
}


int solve()
{
	int time = 0;
	int rotate = 0;
	snake_pos.push_back({ 0, 0 }), board[0][0] = 2;
	auto curr_info = snake_info.begin();
	while (true)
	{
		//print_board(time);
		time++;
		int next_x = snake_pos.front().first + dx[rotate], next_y = snake_pos.front().second + dy[rotate];
		if (!check(next_x, next_y)) return time;	// 벽에 부딛힌다면
		if (board[next_x][next_y] == 2) return time;	// 자기 자신에게 부딪힌다면
		snake_pos.push_front({ next_x, next_y });
		if (board[next_x][next_y] != 1)	//사과를 먹지 않았다면
		{
			board[snake_pos.back().first][snake_pos.back().second] = 0;
			snake_pos.pop_back();
		}
		board[next_x][next_y] = 2;

		if (time == curr_info->first)	// 방향전활 할 단계인가?
		{
			if (curr_info->second == 'L') (rotate += 3) %= 4;
			else if (curr_info->second == 'D') (rotate += 1) %= 4;
			if (curr_info != snake_info.end() - 1) curr_info++;
		}
	}
}

int main()
{
	cin >> N >> K;
	int x, y;
	for (int i = 0; i < K; i++) 
	{
		scanf("%d %d", &x, &y);
		board[x - 1][y - 1] = 1;
	}

	cin >> L;
	int X;
	char C;
	for (int i = 0; i < L; i++)
	{
		scanf("%d %c", &X, &C);
		snake_info.push_back({ X, C });
	}
	cout << solve();
}