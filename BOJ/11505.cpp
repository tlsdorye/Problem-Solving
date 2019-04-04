#include <iostream>
using namespace std;
typedef long long ll;

ll N, M, K;
ll a, b, c;
ll temp = 1000000007;

ll S[1000010];
ll T[3000010];

ll build(ll n, ll s, ll e)
{
	if (s == e) return T[n] = S[s] % temp;
	ll ret1 = build(n * 2, s, (s + e) / 2) % temp;
	ll ret2 = build(n * 2 + 1, (s + e) / 2 + 1, e) % temp;
	return T[n] = (ret1 * ret2) % temp;
}

ll update(ll n, ll s, ll e, ll idx, ll diff)
{
	if (idx < s || e < idx) return T[n];
	if (s == e && e == idx) return T[n] = S[idx] = diff;
	ll ret1 = update(n * 2, s, (s + e) / 2, idx, diff) % temp;
	ll ret2 = update(n * 2 + 1, (s + e) / 2 + 1, e, idx, diff) % temp;
	return T[n] = (ret1*ret2) % temp;
}

ll query(ll n, ll s, ll e, ll l, ll r)
{
	if (r < s || e < l) return 1;
	if (l <= s && e <= r) return T[n];
	ll ret1 = query(n * 2, s, (s + e) / 2, l, r), ret2 = query(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
	return (ret1 * ret2) % temp;
}

void print()
{
	printf("\ntree: ");
	for (int i = 1; i<2*N+1; i++) printf("%lld ", T[i]);
	printf("\n");
}

int main()
{

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> S[i];
		S[i] %= temp;
	}
	build(1, 1, N);

	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, N, b, c%temp);
		else cout << query(1, 1, N, b, c) % temp << "\n";
	}

}