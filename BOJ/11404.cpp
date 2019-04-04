#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define MAX 987654321
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int e[101][101] = {0};
	int x, y, z;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			e[i][j] = MAX;

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		if (e[x][y] > z) e[x][y] = z;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <=n; j++)
			for (int k = 1; k <=n; k++)
				e[k][j] = min(e[k][j], e[k][i] + e[i][j]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || e[i][j] == MAX) e[i][j] = 0;
			cout << e[i][j] << " ";
		}
		cout << endl;
	}
}