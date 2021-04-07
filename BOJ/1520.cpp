#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int N, M;
int grid[501][501];
int dp[501][501];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };


int DFS(int x, int y)
{
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!(0 <= nx && nx < N && 0 <= y && y < M)) continue;
		if (grid[x][y] <= grid[nx][ny]) continue;
		dp[x][y] += DFS(nx, ny);
	}
	return dp[x][y];
}


int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &grid[i][j]);
			dp[i][j] = -1;
		}
	dp[N - 1][M - 1] = 1;
	printf("%d", DFS(0, 0));
}