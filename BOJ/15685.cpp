#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> P;

int grid[101][101];

void MakeDragonCurve(vector<P> &curve, int gen) {
	for (int i = 0; i < gen; i++) {
		int csize = curve.size();
		P rp = curve[csize - 1];
		for (int j = csize - 1; j >= 0; j--) {
			P next_point = { -curve[j].second + rp.first + rp.second, curve[j].first - rp.first + rp.second };
			curve.push_back(next_point);
		}
	}
}

void MarkInGrid(vector<P> &curve, int idx) {
	int csize = curve.size();
	for (int i = 0; i < csize; i++) {
		grid[curve[i].second][curve[i].first] = idx;
	}
}

int GetSquareNum() {
	int ret = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++) {
			if (grid[i][j] == 0) continue;
			if (grid[i + 1][j] == 0) continue;
			if (grid[i][j + 1] == 0) continue;
			if (grid[i + 1][j + 1] == 0) continue;
			ret++;
		}
	return ret;
}

void PrintGrid() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<P> curve;
		curve.push_back({ x, y });
		switch (d) {
		case 0:
			curve.push_back({ x + 1, y });
			break;
		case 1:
			curve.push_back({ x, y - 1 });
			break;
		case 2:
			curve.push_back({ x - 1, y });
			break;
		case 3:
			curve.push_back({ x, y + 1 });
			break;
		default:
			break;
		}
		MakeDragonCurve(curve, g);
		MarkInGrid(curve, i + 1);
		//PrintGrid();
		//MarkInGrid(curve, 0);
	}
	cout << GetSquareNum();
}