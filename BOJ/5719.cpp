#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#define INF 987654321
#define MP make_pair

using namespace std;

vector<pair<int, int>> v[501];
vector<int> path[501];
int dist[501];
int n, m, st, en;

void init() {
	for (int i = 0; i < 501; i++) {
		v[i].clear();
		path[i].clear();
	}
	fill(dist, dist + 501, INF);
    return ;
}

void func(int a, int b) {
	priority_queue<pair<int, int>> Q; // w, v
	Q.push(MP(-0, a));
	dist[a] = 0;

	while (!Q.empty()) {
		int cw = -Q.top().first;
		int cv = Q.top().second;
		Q.pop();
		int size = v[cv].size();
		for (int i = 0; i < size; i++) {
			int nw = v[cv][i].first;
			int nv = v[cv][i].second;

			if (nw < 0) continue;
			if (dist[nv] > cw + nw) {
				dist[nv] = cw + nw;
				Q.push(MP(-dist[nv], nv));

				path[nv].clear();
				path[nv].push_back(cv);
			}
			else if (dist[nv] == nw + cw) {
				path[nv].push_back(cv);
			}
		}
	}
    return ;
}

void bfs(int b) {
	queue<int> q;
	q.push(b); // 도착점

	while (!q.empty()) {
		int cv = q.front();
		q.pop();

		int size = path[cv].size();

		for (int i = 0; i < size; i++) {
			int prev = path[cv][i];

			int ssize = v[prev].size();
			for (int j = 0; j < ssize; j++) {
				if (v[prev][j].second == cv) {
					v[prev][j].first = -1;
				}
			}
			q.push(prev);
		}
	}
    return;
}

int main() {
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin >> st >> en;

		init();
		for (int i = 0; i < m; i++) {
			int a, b, c; cin >> a >> b >> c;
			v[a].push_back(MP(c, b));
		}
		func(st, en);
		bfs(en);
		fill(dist, dist + 501, INF);
		func(st, en);

		if (dist[en] == INF) cout << "-1" << '\n';
		else cout << dist[en] << '\n';
	}
    return 0;
}