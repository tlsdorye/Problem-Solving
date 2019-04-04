#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#define INF 987654321
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int poww(int x)
{
	return x*x;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		P s, e;
		cin >> s.first >> s.second >> e.first >> e.second;
		int n, ans = 0;
		cin >> n;
		vector<vector<int>> d(n, vector<int>());
		for (int i = 0; i < n; i++)
		{
			int sp = 0;
			d[i].resize(3, 0);
			for (int j = 0; j < 3; j++) cin >> d[i][j];
			if (poww(s.first - d[i][0]) + poww(s.second - d[i][1]) <= d[i][2] * d[i][2]) sp++;
			if (poww(e.first - d[i][0]) + poww(e.second - d[i][1]) <= d[i][2] * d[i][2]) sp++;
			if (sp == 1)ans++;
		}
		cout << ans << "\n";
	}
}