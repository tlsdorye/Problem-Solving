#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;


ll T, N;
ll D[3001][3];
ll parent[3001], level[3001];
set<int> S;


ll getLen(ll x, ll y, ll a, ll b)
{
	return (x - a)*(x - a) + (y - b)*(y - b);
}

int find(int n)
{
	if (n == parent[n]) return n;
	return parent[n] = find(parent[n]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (level[u] > level[v]) swap(u, v);
	parent[u] = v;
	if (level[u] == level[v]) level[v]++;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			scanf("%lld %lld %lld", &D[i][0], &D[i][1], &D[i][2]);
			parent[i] = i;
			level[i] = 1;
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (i == j) continue;
				if (getLen(D[i][0], D[i][1], D[j][0], D[j][1]) <= (D[i][2] + D[j][2])*(D[i][2] + D[j][2]))
					merge(i,j);
			}
		for (int i = 0; i < N; i++)
			S.insert(find(i));
		printf("%d\n", S.size());
		S.clear();
	}
}