#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <functional>
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector < vector<double> > d(n, vector<double>());
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			int x;
			double s;
			cin >> x >> s;
			d[x-1].push_back(s);
		}
	vector<double> ans;
	for (int i = 0; i < n; i++)
	{
		sort(d[i].begin(), d[i].end());
		ans.push_back(d[i][d[i].size() - 1]);
	}
	sort(ans.begin(), ans.end(),greater<double>());
	double sum = 0;
	for (int i = 0; i < k; i++)
		sum += ans[i];
	printf("%.1lf", sum);
}