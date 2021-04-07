#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, K;
int visit[500001][2];

bool check(int x) {
	return 0 <= x && x <= 500000;
}

int next_n(int x, int i) {
	if (i == 0) return x + 1;
	else if (i == 1) return x - 1;
	return x * 2;
}

int BFS() {
	queue<int> que;
	que.push(N);
	visit[N][0] = 0;

	int lv = 0;
	int qsize = 0;

	while (!que.empty()) {
		qsize = que.size();
		K += lv;
		if (!check(K)) return -1;

		for (int i = 0; i < qsize; i++) {
			int cur = que.front();
			que.pop();
			if (K == cur || visit[K][lv % 2]) return lv;

			for (int j = 0; j < 3; j++) {
				int next = next_n(cur, j);
				if (!check(next)) continue;
				if (visit[next][(lv + 1) % 2]) continue;
				visit[next][(lv + 1) % 2] = lv + 1;
				que.push(next);
			}
		}
		lv++;
	}
	return -1;
}

int main() {
	cin >> N >> K;
	memset(visit, false, sizeof(visit));
	cout << BFS();
}