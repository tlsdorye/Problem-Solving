#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#define INF 987654321
#define MAX 1000000007
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int dx[3] = {-1,0,-1};
int dy[3] = {0,-1,-1};
int n, m;
vector<vector<ll>> d;

bool bdc(int x,int y)
{
	return x >= 0 && y >= 0;
}


ll solve(int x, int y)
{
	if (!bdc(x, y)) return 0;
	if (d[x][y] == -1) return d[x][y] = (solve(x - 1, y) + solve(x, y - 1) + solve(x - 1, y - 1)) % MAX;
	else
	{
		if (d[x][y] == 0) return 1;
		else return d[x][y];
	}
}

int main()
{
	cin >> n >> m;
	d.resize(n, vector<ll>());
	for (int i = 0; i < n; i++) d[i].resize(m, -1), d[i][0] = 1;
	for (int i = 0; i < m; i++) d[0][i] = 1;
	d[0][0] = 0;
	cout << solve(n - 1, m - 1);
}