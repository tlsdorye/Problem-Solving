#include <iostream>
#include <algorithm>
using namespace std;

int G, P;
int parent[100010];

int find(int n)
{
	if (parent[n] < 0) return n;
	return parent[n] = find(parent[n]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return;
	parent[u] = v;
}

int main()
{
	cin >> G >> P;
	fill(parent, parent + G + 1, -1);
	int x, y, ans = 0;
	bool flag = true;
	for (int i = 0; i < P; i++)
	{
		scanf("%d", &x);
		y = find(x);
		if (y < 1) flag = false;
		if (flag) merge(y, y - 1), ans++;
	}
	cout << ans << "\n";
}