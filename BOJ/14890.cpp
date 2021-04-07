#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, L;
int board[101][101];
int ans = 0;

void solve()
{
	int prev, len, j;
	bool down_state;

	for (int i = 1; i <= N; i++)
	{
		prev = board[1][i], len = 1, down_state = false;
		for (j = 2; j <= N; j++)
		{
			if (board[j][i] == prev)
			{
				len++;
				if(len >= L && down_state) len -= L, down_state = false;
			}
			else if (down_state) break;
			else if (board[j][i] - prev == 1 && len >= L) prev = board[j][i], len = 1;
			else if (board[j][i] - prev == -1)
			{
				prev = board[j][i], len = 1, down_state = true;
				if (len >= L) len -= L, down_state = false;
			}
			else break;
		}
		if (j == N + 1 && !down_state) ans++;
	}
	for (int i = 1; i <= N; i++)
	{
		prev = board[i][1], len = 1, down_state = false;
		for (j = 2; j <= N; j++)
		{
			if (board[i][j] == prev)
			{
				len++;
				if (len >= L && down_state) len -= L, down_state = false;
			}
			else if (down_state) break;
			else if (board[i][j] - prev == 1 && len >= L) prev = board[i][j], len = 1;
			else if (board[i][j] - prev == -1)
			{
				prev = board[i][j], len = 1, down_state = true;
				if (len >= L) len -= L, down_state = false;
			}
			else break;
		}
		if (j == N + 1 && !down_state) ans++;
	}
}


int main()
{
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) scanf("%d", &board[i][j]);
	solve();
	cout << ans;
}