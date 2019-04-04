#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int T, N;
int parent[200001];

int find(int n)
{
	if (parent[n] < 0) return n;
	return parent[n] = find(parent[n]);
}

int merge(int u, int  v)
{
	u = find(u);
	v = find(v);
	if (u == v) return -parent[u];
	if (parent[u] < parent[v]) swap(u, v);
	parent[v] += parent[u];
	parent[u] = v;
	return -parent[v];
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		fill(parent, parent + N * 2 , -1);
		int Np = 0;
		char u[21], v[21];
		map<string, int> P;
		for (int i = 0; i < N; i++)
		{
			scanf("%s %s", u, v);
			if (P.find(u) == P.end()) P[u] = Np++;
			if (P.find(v) == P.end()) P[v] = Np++;
			cout << merge(P[u], P[v]) << "\n";
		}
	}
}