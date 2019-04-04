#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, L;
int parent[300010][2];
int D[300010];
vector<string> T;

int find(int n)
{
	if (parent[n][0] <= 0) return n;
	return parent[n][0] = find(parent[n][0]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u != v)
	{
		if (parent[u][0] < parent[v][0]) swap(u, v);
		parent[v][0] += parent[u][0];
		parent[u][0] = v;
		parent[v][1] += parent[u][1];
	}

	if (parent[v][1] + 1 <= (-parent[v][0]))
	{
		printf("LADICA\n");
		parent[v][1]++;
	}
	else printf("SMECE\n");
}

int main()
{
	cin >> N >> L;
	for (int i = 1; i <= L; i++) parent[i][0] = -1;
	int a, b;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &a, &b);
		merge(a, b);
	}

	for (int i = 0; i < T.size(); i++)
		cout << T[i] << "\n";
}