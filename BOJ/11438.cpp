#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

int N, M;
vector<vector<int>> adj;
vector<bool> check;
vector<P> node;
vector<P> tree;

int node_to_idx[100002];

P build(int n, int s, int e)
{
	if (s == e) return tree[n] = node[s];
	int mid = (s + e) / 2;
	P a = build(n * 2, s, mid);
	P b = build(n * 2 + 1, mid + 1, e);
	if (a.first > b.first) return tree[n] = b;
	else return tree[n] = a;
}

P query(int n, int s, int e, int l, int r)
{
	if (r < s || e < l) return { 1000000, 0 };
	if (l <= s && e <= r) return tree[n];
	int mid = (s + e) / 2;
	P a = query(n * 2, s, mid, l, r);
	P b = query(n * 2 + 1, mid + 1, e, l, r);
	if (a.first > b.first) return b;
	else return a;
}

void DFS(int depth, int U)
{
	check[U] = true;
	node.push_back({ depth, U });
	for (int V : adj[U])
	{
		if (check[V]) continue;
		DFS(depth + 1, V);
		node.push_back({ depth, U });
	}
}

int main()
{
	scanf("%d", &N);

	adj.resize(N + 1);
	check.resize(N + 1);
	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	node.push_back({ 0, 0 });
	DFS(0, 1);
	for (int i = 1; i < node.size(); i++)
	{
		P p = node[i];
		if (node_to_idx[p.second] != 0) continue;
		node_to_idx[p.second] = i;
	}
	int leaf_cnt = node.size() - 1;
	tree.resize(4 * leaf_cnt + 1);
	build(1, 1, leaf_cnt);

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		int adx = node_to_idx[a];
		int bdx = node_to_idx[b];
		if (adx > bdx) swap(adx, bdx);
		printf("%d\n", query(1, 1, leaf_cnt, adx, bdx).second);
	}
}