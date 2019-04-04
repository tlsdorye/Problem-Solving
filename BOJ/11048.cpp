#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#include <map>
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> d[i][j];
			d[i][j] += max(max(d[i - 1][j - 1], d[i - 1][j]), d[i][j - 1]);
		}
	cout << d[n][m];
}