#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool check(int x, int y, int m, int n) {
	return 0 <= x && x < m && 0 <= y && y < n;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	queue<P> que;
	vector<vector<bool>> visit(m, vector<bool>(n, false));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (visit[i][j]) continue;
			visit[i][j] = true;
			if (picture[i][j] == 0) continue;
			while (!que.empty()) que.pop();

			que.push({ i, j });
			int size = 0;
			while (!que.empty()) {
				P cur = que.front();
				que.pop();
				size++;
				int cx = cur.first;
				int cy = cur.second;
				for (int k = 0; k < 4; k++) {
					int nx = cx + dx[k];
					int ny = cy + dy[k];
					if (!check(nx, ny, m, n)) continue;
					if (visit[nx][ny]) continue;
					if (picture[cx][cy] != picture[nx][ny]) continue;
					que.push({ nx, ny });
					visit[nx][ny] = true;
				}
			}
			number_of_area++;
			max_size_of_one_area = max(max_size_of_one_area, size);
		}


	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}