#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> P;

vector<int> BFS(int n, vector<vector<int>> &adj, int s) {
	queue<int> que;
	que.push(s);

	vector<bool> visit(n + 1, false);
	visit[s] = true;

	int level = 0;
	int qsize = 0;
	int cur = -1;
	while (!que.empty()) {
		qsize = que.size();
		for (int i = 0; i < qsize; i++) {
			cur = que.front();
			que.pop();

			for (int next : adj[cur]) {
				if (visit[next]) continue;
				visit[next] = true;
				que.push(next);
			}
		}
		if (que.empty()) break;
		level++;
	}
	return { cur, qsize, level };
}

int solution(int n, vector<vector<int>> edges) {
	int answer = 0;

	vector<vector<int>> adj(n + 1, vector<int>());
	for (vector<int> x : edges) {
		adj[x[0]].push_back(x[1]);
		adj[x[1]].push_back(x[0]);
	}

	vector<int> u = BFS(n, adj, 1);
	vector<int> v = BFS(n, adj, u[0]);
	vector<int> w = BFS(n, adj, v[0]);

	answer = v[2];
	if (v[1] == 1 && w[1] == 1) answer--;

	return answer;
}