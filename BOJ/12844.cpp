#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;

ll N, M;
ll t, a, b, c;
ll S[1000000], T[2000000], lazy[2000000];

void propagate(ll n, ll s, ll e)
{
	if (lazy[n] == 0) return;
	if ((e - s + 1) % 2 == 1) T[n] ^= lazy[n];
	if (s != e)
	{
		lazy[n * 2] ^= lazy[n];
		lazy[n * 2 + 1] ^= lazy[n];
	}
	lazy[n] = 0;
	return;
}

void update(ll n, ll s, ll e, ll l, ll r, ll diff)
{
	propagate(n, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r)
	{
		lazy[n] ^= diff;
		propagate(n, s, e);
		return;
	}
	update(n * 2, s, (s + e) / 2, l, r, diff);
	update(n * 2 + 1, (s + e) / 2 + 1, e, l, r, diff);
	T[n] = T[n * 2] ^ T[n * 2 + 1];
}

ll query(ll n, ll s, ll e, ll l, ll r)
{
	propagate(n, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return T[n];
	return query(n * 2, s, (s + e) / 2, l, r) ^ query(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

void print()
{
	printf("\nTree: ");
	for (int i = 1; i <= 3 * N; i++)
		printf("%2lld ", T[i]);
	printf("\nlazy: ");
	for (int i = 1; i <= 3 * N; i++)
		printf("%2lld ", lazy[i]);
	printf("\n");
}

int main()
{
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &S[i]);
		update(1, 1, N, i, i, S[i]);
	}
	scanf("%lld", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%lld", &t);
		if (t == 1)
		{
			scanf("%lld%lld%lld", &a, &b, &c);
			if (a > b) swap(a, b);
			update(1, 1, N, a + 1, b + 1, c);
		}
		else
		{
			scanf("%lld%lld", &a, &b);
			if (a > b) swap(a, b);
			printf("%lld\n", query(1, 1, N, a + 1, b + 1));
		}
	}

}