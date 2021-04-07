#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> T;

int parent[101];
int level[101];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (level[u] > level[v]) swap(u, v);
	parent[u] = v;
	if (level[u] == level[v]) level[v]++;
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	priority_queue<T, vector<T>, greater<T>> edges;
	for (vector<int> x : costs) edges.push({ x[2], x[0], x[1] });

	for (int i = 0; i < n; i++) {
		parent[i] = i;
		level[i] = 1;
	}

	int cnt = 0;
	while (cnt < n - 1) {
		int w, u, v;
		tie(w, u, v) = edges.top();
		edges.pop();

		if (find(u) == find(v)) continue;
		merge(u, v);
		answer += w;
		cnt++;
	}

	return answer;
}