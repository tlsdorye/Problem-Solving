#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int d[100][100] = { 0 };
	int t;
	cin >> t;
	vector<pair<int, int>> p(t, pair<int, int>());
	for (int i = 0; i < t; i++) cin >> p[i].first >> p[i].second;
	for (int i = 0; i < t; i++)
	{
		for (int j = p[i].first; j < p[i].first + 10; j++)
			for (int k = p[i].second; k < p[i].second + 10; k++)
				d[j][k] = 1;
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (d[i][j] == 1) ans += 1;
	cout << ans;
}