#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, ans;

vector<vector<int>> edge;
bool visit[2001];

void dfs(int v, int depth) {
	visit[v] = true;
	if (depth == 4) {
		ans = 1;
		return;
	}
	for (int x : edge[v]) {
		if (visit[x]) continue;
		visit[x] = true;
		dfs(x, depth + 1);
	}
	visit[v] = false;
}

int main()
{
	cin >> N >> M;
	edge.resize(N, vector<int>());
	int x, y;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	for (int i = 0; i < N; i++) {
		if (ans == 1) break;
		dfs(i, 0);
	}
	cout << ans;
}