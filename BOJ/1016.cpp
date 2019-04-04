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
	ll n, m;
	cin >> n >> m;
	vector<int> d(m - n + 1, 0);
	for (ll i = 2; i <= sqrt(m) + 1; i++)
	{
		ll g = i*i;
		for (ll k = (n / g)*g; k <= m; k += g)
			if (n <= k && k <= m) d[k-n] = 1;
	}
	ll ans = 0;
	for (int i = 0; i < d.size(); i++) if (d[i] == 0) ans++;
	cout << ans;
}