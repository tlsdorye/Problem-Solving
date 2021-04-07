#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int D[5][2] = {
	{},
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

int N, M, K, REST, ANS;
vector<vector<P>> grid;
int shark[401][4];
int sdx[401][5][4];

bool check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void move_shark() {
	for (int i = 1; i <= M; i++) {
		if (!shark[i][0]) continue;
		int cx = shark[i][1], nx = -1;
		int cy = shark[i][2], ny = -1;
		int cd = shark[i][3], nd = -1;
		bool flag = true;
		for (int j = 0; j < 4; j++) {
			nd = sdx[i][cd][j];
			nx = cx + D[nd][0];
			ny = cy + D[nd][1];
			if (!check(nx, ny)) continue;
			if (grid[nx][ny].first != 0) continue;
			flag = false;
			break;
		}
		for (int j = 0; j < 4 && flag; j++) {
			nd = sdx[i][cd][j];
			nx = cx + D[nd][0];
			ny = cy + D[nd][1];
			if (!check(nx, ny)) continue;
			if (grid[nx][ny].first == i) break;
		}
		shark[i][1] = nx;
		shark[i][2] = ny;
		shark[i][3] = nd;
	}
}

void down_smell() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			grid[i][j].second--;
			if (grid[i][j].second <= 0) 
				grid[i][j] = { 0, 0 };
		}
}

int drop_shark() {
	int ret = 0;
	for (int i = 1; i <= M; i++) {
		if (!shark[i][0]) continue;
		int x = shark[i][1];
		int y = shark[i][2];
		if (grid[x][y].first != 0
			&& grid[x][y].first != i) {
			shark[i][0] = 0;
			ret++;
			continue;
		}
		grid[x][y] = { i, K };
	}
	return ret;
}

int solve() {
	REST = M;
	while (REST > 1) {
		if (ANS >= 1000) return -1;
		move_shark();
		down_smell();
		REST -= drop_shark();
		ANS++;
	}
	return ANS;
}

int main() {
	cin >> N >> M >> K;

	int x;
	grid.resize(N, vector<P>());
	for (int i = 0; i < N; i++) {
		grid[i].resize(N, {});
		for (int j = 0; j < N; j++) {
			cin >> x;
			if (x > 0) {
				grid[i][j] = { x, K };
				shark[x][0] = 1;
				shark[x][1] = i;
				shark[x][2] = j;
			}
		}
	}

	for (int i = 1; i <= M; i++)
		cin >> shark[i][3];

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= 4; j++) {
			cin >> sdx[i][j][0] >> sdx[i][j][1];
			cin >> sdx[i][j][2] >> sdx[i][j][3];
		}
	cout << solve();
}