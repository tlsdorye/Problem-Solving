#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll N, Q;
ll S[100010], T[300010];
vector<P> V;

ll build(ll n, ll s, ll e)
{
	if (s == e) return T[n] = S[s];
	return T[n] = build(n * 2, s, (s + e) / 2) + build(n * 2 + 1, (s + e) / 2 + 1, e);
}

void update(ll n, ll s, ll e, ll idx, ll diff)
{
	if (idx < s || e < idx) return;
	T[n] += diff;
	if (s == e) return;
	update(n * 2, s, (s + e) / 2, idx, diff);
	update(n * 2 + 1, (s + e) / 2 + 1, e, idx, diff);
}

ll query(ll n, ll s, ll e, ll l, ll r)
{
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return T[n];
	ll ret1 = query(n * 2, s, (s + e) / 2, l, r);
	ll ret2 = query(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
	return ret1 + ret2;
}

void print()
{
	printf("\nTree: ");
	for (int i = 1; i <= 3 * N; i++) printf("%lld ", T[i]);
	printf("\n");
	return;
}

int main()
{
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) scanf("%lld", &S[i]);
	build(1, 1, N);

	ll x, y, a, b;

	for (int i = 1; i <= Q; i++)
	{
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if (x > y) swap(x, y);
		printf("%lld\n", query(1, 1, N, x, y));
		ll diff = b - S[a];
		S[a] = b;
		update(1, 1, N, a, diff);
	}
	
}