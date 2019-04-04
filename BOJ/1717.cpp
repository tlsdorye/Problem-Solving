#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, M;
int parent[1000010], level[1000010];

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
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1)
		{
			if (find(b) == find(c)) printf("YES\n");
			else printf("NO\n");
		}
		else merge(b, c);
	}
}