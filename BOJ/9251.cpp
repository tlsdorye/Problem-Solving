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
	string n, m;
	cin >> n >> m;
	vector<vector<int>> d(n.size()+1, vector<int>(m.size()+1, 0));
	for (int i = 1; i <= n.size(); i++)
		for (int j = 1; j <= m.size(); j++)
		{
			if (n[i-1] == m[j-1]) d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	cout << d[n.size()][m.size()];
}