#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

class node
{
public:
	ll x, y, idx;
	node(ll x, ll y)
	{
		this->x = x;
		this->y = y;
		idx = 0;
	}
};

bool sortByX(node &u, node &v)
{
	return (u.x != v.x) ? (u.x < v.x) : (u.y > v.y);
}

bool sortByY(node &u, node &v)
{
	return (u.y != v.y) ? (u.y > v.y) : (u.x < v.x);
}

ll test_case, N, T[300100], ans;
vector<node> S;

ll build(ll n, ll s, ll e)
{
	if (s == e) return T[n] = 1;
	return T[n] = build(n * 2, s, (s + e) / 2) + build(n * 2 + 1, (s + e) / 2 + 1, e);
}

void update(ll n, ll s, ll e, ll idx)
{
	if (idx < s || e < idx) return;
	T[n]--;
	if (s == e) return;
	update(n * 2, s, (s + e) / 2, idx);
	update(n * 2 + 1, (s + e) / 2 + 1, e, idx);
}

ll query(ll n, ll s, ll e, ll l, ll r)
{
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return T[n];
	return query(n * 2, s, (s + e) / 2, l, r) + query(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

void printNode()
{
	printf("\nNode: ");
	for (int i = 0; i < N; i++)
		printf("[%lld %lld %lld] ", S[i].x, S[i].y, S[i].idx);
	printf("\n");
}

void printTree()
{
	printf("\nTree: ");
	for (int i = 0; i < 3*N; i++)
		printf("%lld ", T[i]);
	printf("\n");
}


int main()
{
	cin >> test_case;
	while (test_case--)
	{
		cin >> N;
		ll x, y;
		for (int i = 0; i < N; i++)
		{
			scanf("%lld %lld", &x, &y);
			S.push_back(node(x, y));
		}
		sort(S.begin(), S.end(), sortByX);
		for (int i = 0; i < S.size(); i++)
			S[i].idx = i+1;
		//printNode();
		sort(S.begin(), S.end(), sortByY);
		//printNode();
		build(1,1,N);
		//printTree();
		for (int i = 0; i < N; i++)
		{
			//ll result = query(1, 1, N, S[i].idx, N) - 1;
			ans += query(1, 1, N, S[i].idx, N) - 1;
			update(1, 1, N, S[i].idx);
			//printTree();
			//printf("result: %d\n", result);
		}
		printf("%lld\n", ans);

		S.clear();
		memset(T, sizeof(T), 0);
		ans = 0;
	}
}
