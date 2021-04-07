#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <string.h>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef tuple<int, int, int, int, int> TP;

int T, N;

int map[11][11];
int dt[3] = { 4, 4, 8 };
int dx[3][8] = { { 0, 0, 1, -1 }, { 1, 1, -1, -1}, { 2, 2, -2, -2, 1, 1, -1, -1 } };
int dy[3][8] = { { 1, -1, 0, 0 }, { 1, -1, 1, -1}, { 1, -1, 1, -1, 2, -2, 2, -2 } };

bool check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

int BFS(int x, int y) {
	// cur_num, type, move, x, y
	queue<TP> que;
	que.push({ 1, 0, 0, x, y });
	que.push({ 1, 1, 0, x, y });
	que.push({ 1, 2, 0, x, y });

	// cur_num, type, x, y
	bool visit[101][3][11][11] = { false, };
	visit[1][0][x][y] = true;
	visit[1][1][x][y] = true;
	visit[1][2][x][y] = true;

	int cn, ct, cm, cx, cy;
	int nn, nx, ny;
	while (!que.empty()) {
		TP cur = que.front();
		que.pop();

		tie(cn, ct, cm, cx, cy) = cur;
		if (cn == N * N) return cm;

		// 현재 위치에서 다른 말로 교환
		for (int i = 0; i < 3; i++) {
			if (ct == i) continue;
			if (visit[cn][i][cx][cy]) continue;
			que.push({ cn, i, cm + 1, cx, cy });
		}

		// 위치 이동
		for (int i = 0; i < dt[ct]; i++) {
			nx = cx + dx[ct][i];
			ny = cy + dy[ct][i];
			if (!check(nx, ny)) continue;
			map[nx][ny] == cn + 1 ? nn = cn + 1 : nn = cn;
			if (!visit[nn][ct][nx][ny]) {
				visit[nn][ct][nx][ny] = true;
				que.push({ nn, ct, cm + 1, nx, ny });
			}

			if (ct != 2) {
				while (check(nx += dx[ct][i], ny += dy[ct][i])) {
					map[nx][ny] == cn + 1 ? nn = cn + 1 : nn = cn;
					if (visit[nn][ct][nx][ny]) continue;
					visit[nn][ct][nx][ny] = true;
					que.push({ nn, ct, cm + 1, nx, ny });
				}
			}
		}
	}
}


int main() {
	cin >> N;

	P S;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) S = { i, j };
		}

	cout << BFS(S.first, S.second);

}