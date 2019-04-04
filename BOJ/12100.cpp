#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll map[21][21];
int n;

void move(int dir) {
	if (dir == 0) { //오른쪽
		for (int i = 0; i < n; i++) {
			int right = n - 1, left = n - 1;
			while (right >= 0 && left >= 0) {
				//cout << right << " " << left << endl;

				if (map[i][right] == 0) {
					while (left >= 0) {
						if (map[i][left] != 0) {
							map[i][right] = map[i][left];
							map[i][left] = 0;
							break;
						}
						left--;
					}
				}
				else {
					while (left >= 0) {
						left--;
						if (map[i][left] != 0) {
							if (map[i][right] == map[i][left]) {
								map[i][right] *= 2;
								map[i][left] = 0;
							}
							right--;
							break;
						}
					}
				}
			}
		}
	}
	if (dir == 1) {	// 아래
		for (int i = 0; i < n; i++) {
			int down = n - 1, up = n - 1;
			while (down >= 0 && up >= 0) {
				if (map[down][i] == 0) {
					while (up >= 0) {
						if (map[up][i] != 0) {
							map[down][i] = map[up][i];
							map[up][i] = 0;
							break;
						}
						up--;
					}
				}
				else {
					while (up >= 0) {
						up--;
						if (map[up][i] != 0) {
							if (map[down][i] == map[up][i]) {
								map[down][i] *= 2;
								map[up][i] = 0;
							}
							down--;
							break;
						}
					}
				}
			}
		}
	}
	if (dir == 2) {	//왼쪽
		for (int i = 0; i < n; i++) {
			int right = 0, left = 0;
			while (right < n && left < n) {
				if (map[i][left] == 0) {
					while (right < n) {
						if (map[i][right] != 0) {
							map[i][left] = map[i][right];
							map[i][right] = 0;
							break;
						}
						right++;
					}
				}
				else {
					while (right < n) {
						right++;
						if (map[i][right] != 0) {
							if (map[i][left] == map[i][right]) {
								map[i][left] *= 2;
								map[i][right] = 0;
							}
							left++;
							break;
						}
					}
				}
			}
		}
	}
	if (dir == 3) { // 위
		for (int i = 0; i < n; i++) {
			int down = 0, up = 0;
			while (down < n && up < n) {
				if (map[up][i] == 0) {
					while (down < n) {
						if (map[down][i] != 0) {
							map[up][i] = map[down][i];
							map[down][i] = 0;
							break;
						}
						down++;
					}
				}
				else {
					while (down < n) {
						down++;
						if (map[down][i] != 0) {
							if (map[up][i] == map[down][i]) {
								map[up][i] *= 2;
								map[down][i] = 0;
							}
							up++;
							break;
						}
					}
				}
			}
		}
	}
}

int getMax() {
	int maxx = map[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (maxx < map[i][j]) maxx = map[i][j];
	return maxx;
}

int solve(int index) {
	if (index >= 5) return getMax();
	int ans = 0;
	int tmap[21][21];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmap[i][j] = map[i][j];

	for (int i = 0; i < 4; i++) {
		move(i);
		int tans = solve(index + 1);
		if (ans < tans) ans = tans;

		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				map[j][k] = tmap[j][k];
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	cout << solve(0);
}