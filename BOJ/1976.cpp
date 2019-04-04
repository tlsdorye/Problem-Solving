#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, M;
int parent[1000], level[1000], travel[1000];

void init(int n)
{
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
		level[i] = 1;
	}
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
	cin >> N >> M;
	init(N);
	int x;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &x);
			if (x == 1) merge(i, j);
		}
	for (int i = 0; i < M; i++)
		scanf("%d", &travel[i]);
	int root = find(travel[0]);
	for (int i = 1; i < M; i++)
		if (root != find(travel[i]))
		{
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}