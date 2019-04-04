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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n+1);
	for (int i = 1; i <= n; i++)
	{
		v[i].resize(m+1);
		for (int j = 1; j <= m; j++) cin >> v[i][j];
	}
	int k, a, b, x, y;
	cin >> k;
	while (k--)
	{
		int ans = 0;
		cin >> a >> b >> x >> y;
		for (int i = a; i <= x; i++)
			for (int j = b; j <= y; j++) ans += v[i][j];
		cout << ans << endl;
	}
}