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
	int t;
	vector<int> coin;
	vector<ll> d;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		coin.resize(n);
		for (int i = 0; i < n; i++) cin >> coin[i];
		cin >> m;
		d.resize(m + 1);
		for (int i = 0; i < n; i++)
		{
			if (coin[i] > m) continue;
			d[coin[i]] ++;
			for (int j = coin[i] + 1; j <= m; j++) d[j] += d[j - coin[i]];
		}
		cout << d[m] << endl;
		d.clear();
		coin.clear();
	}
}