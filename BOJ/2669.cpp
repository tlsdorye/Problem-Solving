#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <utility>
typedef long long ll;
using namespace std;

int main() {
	int p[100][100] = { 0 };
	int x, y, z, w;
	for (int i = 0; i < 4; i++) {
		cin >> x >> y >> z >> w;
		for (int k = x; k < z; k++)
			for (int j = y; j < w; j++)
				p[k][j] = 1;
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (p[i][j] == 1)ans++;
	cout << ans;
}