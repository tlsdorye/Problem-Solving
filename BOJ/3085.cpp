#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int n;
vector<vector<char>> d;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool bdc(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

int check(int idx, bool flag)
{
	int sp = 1, ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (flag)
		{
			if (d[idx][i - 1] == d[idx][i])
				ans = max(ans, ++sp);
			else sp = 1;
		}
		else
		{
			if (d[i - 1][idx] == d[i][idx])
				ans = max(ans, ++sp);
			else sp = 1;
		}
	}
	return ans;
}


int solve()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (bdc(i + dx[k], j + dy[k]))
				{
					swap(d[i][j], d[i + dx[k]][j + dy[k]]);
					ans = max(ans, check(i, 1));
					ans = max(ans, check(i + dx[k], 1));
					ans = max(ans, check(j, 0));
					ans = max(ans, check(j + dy[k], 0));
					swap(d[i][j], d[i + dx[k]][j + dy[k]]);
				}
			}
		}
	}
	return ans;
}

int main()
{
	cin >> n;
	d.resize(n, vector<char>());
	for (int i = 0; i < n; i++)
	{
		d[i].resize(n, 0);
		for (int j = 0; j < n; j++)
			cin >> d[i][j];
	}
	int ans = solve();
	cout << ans;
}