#include <string>
#include <vector>

using namespace std;

void solve(vector<vector<int>> adj, vector<bool> &visit, int cur) {
	visit[cur] = true;
	for (int next : adj[cur]) {
		if (visit[next]) continue;
		solve(adj, visit, next);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	vector<vector<int>> adj(n, vector<int>());
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (computers[i][j] == 0) continue;
			adj[i].push_back(j);
		}

	vector<bool> visit(n, false);
	for (int i = 0; i < n; i++)
		if (!visit[i]) {
			solve(adj, visit, i);
			answer++;
		}

	return answer;
}