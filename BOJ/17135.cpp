#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> P;

int N, M, D, Ne, ans;
int grid[16][16], cgrid[16][16];
int dx[3] = { 0, -1, 0 };
int dy[3] = { -1, 0, 1 };
vector<P> archer;

bool check(int x, int y) {
	return 0 <= x && x <= N && 0 <= y && y < M;
}

void attack() {
	int Nk = 0;
	int CNe = Ne;
	memcpy(cgrid, grid, sizeof(grid));
	while (CNe > 0) {
		for (P a : archer) {
			bool visit[16][16] = { false };
			queue<P> que;
			que.push({ a.first, a.second });
			visit[a.first][a.second] = true;

			int level = 0;
			while (!que.empty()) {
				if (level > D) break;
				int qsize = que.size();
				for (int i = 0; i < qsize; i++) {
					P cur = que.front();
					que.pop();

					int cx = cur.first;
					int cy = cur.second;
					if (cgrid[cx][cy] >= 1) {
						cgrid[cx][cy]++;
						level = D + 1;
						break;
					}
					for (int j = 0; j < 3; j++) {
						int nx = cx + dx[j];
						int ny = cy + dy[j];
						if (!check(nx, ny)) continue;
						if (visit[nx][ny]) continue;
						visit[nx][ny] = true;
						que.push({ nx, ny });
					}
				}
				level++;
			}
		}
		for (int i = N - 1; i >= 0; i--)
			for (int j = 0; j < M; j++) {
				if (cgrid[i][j] == 1) {
					cgrid[i][j] = 0;
					if (i == N - 1) CNe--;
					else cgrid[i + 1][j] = 1;
				}
				if (cgrid[i][j] >= 2) {
					Nk++;
					CNe--;
					cgrid[i][j] = 0;
				}
			}
	}
	ans = max(ans, Nk);
}

void solve(int idx) {
	if (archer.size() == 3) {
		attack();
		return;
	}
	for (int i = idx; i < M; i++) {
		archer.push_back({ N, i });
		solve(i + 1);
		archer.pop_back();
	}
}

int main() {
	cin >> N >> M >> D;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) Ne++;
		}
	solve(0);
	cout << ans;
}