#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, Q, a, b, c;
ll S[1000010];
ll T[3000010];

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
	return query(n * 2, s, (s + e) / 2, l, r) + query(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
}


int main()
{
	cin >> N >> Q;
	for (int i = 1; i <= Q; i++)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1)
		{
			S[b] += c;
			update(1, 1, N, b, c);
		}
		else printf("%lld\n", query(1, 1, N, b, c));
	}
}