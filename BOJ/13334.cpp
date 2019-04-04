#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll N, L;
vector<P> V, D;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		if (x < y) V.push_back(make_pair(x, y));
		else V.push_back(make_pair(y, x));
	}
	cin >> L;
	for (int i = 0; i < N; i++)
		if (V[i].second - V[i].first <= L)
		{
			D.push_back(make_pair(V[i].first, 1));
			D.push_back(make_pair(V[i].second - L, -1));
		}
	sort(D.begin(), D.end());
	ll ans = 0, curr = 0;
	for (int i = 0; i < D.size(); i++)
	{
		if (D[i].second == -1) curr += 1;
		else curr -= 1;
		ans = max(ans, curr);
	}
	cout << ans;
	return 0;
}