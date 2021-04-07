#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N;
ll grid[33][33];
ll dp[3][33][33];

void solve()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 3; j <= N; j++)
		{
			if (grid[i][j] == 0)
			{
				if (grid[i - 1][j] == 0 && grid[i][j - 1] == 0)
				{
					dp[1][i][j] += dp[0][i - 1][j - 1];
					dp[1][i][j] += dp[1][i - 1][j - 1];
					dp[1][i][j] += dp[2][i - 1][j - 1];
				}
				dp[0][i][j] += (dp[0][i][j - 1] + dp[1][i][j - 1]);
				dp[2][i][j] += (dp[2][i - 1][j] + dp[1][i - 1][j]);

			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%lld", &grid[i][j]);
	dp[0][1][2] = 1;

	solve();
	ll ans = dp[0][N][N] + dp[1][N][N] + dp[2][N][N];
	cout << ans;
}