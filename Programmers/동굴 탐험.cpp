#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;


bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	bool answer = true;

	vector<vector<int>> adj(n, vector<int>());
	for (vector<int> x : path) {
		adj[x[0]].push_back(x[1]);
		adj[x[1]].push_back(x[0]);
	}

	vector<bool> lock(n, false);
	map<int, int> odr;
	for (vector<int> x : order) {
		if (x[1] == 0) return false;
		lock[x[1]] = true;
		odr[x[0]] = x[1];
	}

	queue<int> que;
	que.push(0);

	vector<bool> visit(n, false);
	visit[0] = true;

	set<int> wait;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (odr.find(cur) != odr.end()) {
			int lock_node = odr[cur];
			lock[lock_node] = false;
			
			if (wait.find(lock_node) != wait.end()) {
				visit[lock_node] = true;
				que.push(lock_node);
				wait.erase(lock_node);
			}
		}

		for (int next : adj[cur]) {
			if (visit[next]) continue;
			if (lock[next]) wait.insert(next);
			else {
				visit[next] = true;
				que.push(next);
			}
		}
	}

	for (bool v : visit) answer &= v;
	return answer;
}