#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, M;
ll a, b;

ll S[100010], T[300010];

ll build(ll n, ll s, ll e)
{
	if (s == e) return T[n] = S[s];
	ll ret1 = build(n * 2, s, (s + e) / 2), ret2 = build(n * 2 + 1, (s + e) / 2 + 1, e);
	return T[n] = min(ret1, ret2);
}

ll query(ll n, ll s, ll e, ll l, ll r)
{
	if (r < s || e < l) return 1000000001;
	if (l <= s && e <= r) return T[n];
	ll ret1 = query(n * 2, s, (s + e) / 2, l, r), ret2 = query(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
	return min(ret1, ret2);
}

int main()
{
	scanf("%lld %lld", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%lld", &S[i]);
	build(1, 1, N);

	for (int i = 0; i < M; i++)
	{
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", query(1, 1, N, a, b));
	}
}