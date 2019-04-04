#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll N;
ll S[1000010], T[3000010];
vector<P> V;

void update(ll n, ll s, ll e, ll idx, ll diff)
{
	if (idx < s || e < idx) return;
	T[n] = max(T[n], diff);
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
	return max(ret1, ret2);
}

void print()
{
	printf("\nTree: ");
	for (int i = 1; i <= 3 * N; i++) printf("%lld ", T[i]);
	printf("\n");
	return;
}

bool comp(const P& p, const P& q)
{
	if (p.first < q.first) return true;
	if (p.first > q.first) return false;
	return p.second > q.second;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &S[i]);
		V.push_back(make_pair(S[i], i));
	}
	sort(V.begin(), V.end(), comp);
	for (int i = 0; i < N; i++)
	{
		ll temp = query(1, 1, N, 1, V[i].second);
		update(1, 1, N, V[i].second, temp + 1);
		//print();
	}
	printf("%lld\n", T[1]);
}