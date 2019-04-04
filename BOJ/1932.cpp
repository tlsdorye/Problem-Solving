#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#define INF 987654321
typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<ll>> t(n + 1);
	vector<vector<ll>> d(n + 1);
	for (int i = 1; i <= n; i++)
	{
		t[i].resize(i);
		d[i].resize(i);
		for (int j = 0; j < i; j++)
		{
			cin >> t[i][j];
			if (i == 1 && j == 0) d[i][j] = t[i][j];
			else if (j == 0) d[i][j] = t[i][j] + d[i - 1][j];
			else if (j == i - 1) d[i][j] = t[i][j] + d[i - 1][j-1];
			else d[i][j] = max(t[i][j] + d[i - 1][j], t[i][j] + d[i - 1][j - 1]);
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) ans = max(ans, d[n][i]);
	cout << ans;
}