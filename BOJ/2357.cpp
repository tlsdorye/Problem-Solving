#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;


ll N, M, K;
ll a, b;

ll S[100010];
ll T[300010][2];
P temp = make_pair(1000000001, 0);

void build(ll n, ll s, ll e)
{
	if (s == e)
	{
		T[n][0] = T[n][1] = S[s];
		return;
	}
	build(n * 2, s, (s + e) / 2);
	build(n * 2 + 1, (s + e) / 2 + 1, e);
	T[n][0] = min(T[n * 2][0], T[n * 2 + 1][0]);
	T[n][1] = max(T[n * 2][1], T[n * 2 + 1][1]);
}

ll MINquery(ll n, ll s, ll e, ll l, ll r)
{
	if (r < s || e < l) return 1000000001;
	if (l <= s && e <= r) return T[n][0];
	ll ret1 = MINquery(n * 2, s, (s + e) / 2, l, r), ret2 = MINquery(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
	return min(ret1, ret2);
}

ll MAXquery(ll n, ll s, ll e, ll l, ll r)
{
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return T[n][1];
	ll ret1 = MAXquery(n * 2, s, (s + e) / 2, l, r), ret2 = MAXquery(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
	return max(ret1, ret2);
}

int main()
{

	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> S[i];
	build(1, 1, N);

	for (int i = 0; i < M; i++)
	{
		scanf("%lld %lld", &a, &b);
		printf("%lld %lld\n", MINquery(1, 1, N, a, b), MAXquery(1, 1, N, a, b));
	}

}