#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, M;
bool D[10];

bool check(ll x)
{
	if (x == 0) return D[0];
	while (x > 0)
	{
		if (!D[x % 10]) return false;
		x /= 10;
	}
	return true;
}

ll length(ll x)
{
	if (x == 0) return 1;
	ll ret = 0;
	while (x > 0)
	{
		x /= 10;
		ret++;
	}
	return ret;
}

int main()
{
	for (int i = 0; i < 10; i++) D[i] = true;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		ll x;
		cin >> x;
		D[x] = false;
	}
	
	ll ans = abs(N - 100);
	if (ans == 0)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i <= 1000000; i++)
	{
		if (!check(i)) continue;
		ans = min(ans, abs(N - i) + length(i));
	}
	cout << ans;
	return 0;
}