#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <set>
using namespace std;

int N;
int D[4] = { 1, 5, 10, 50 };
set<int> S;

void solve(int depth, int rest, vector<int> &sel) {
	if (depth == 3) {
		sel.push_back(rest);
		int ret = 0;
		for (int i = 0; i < 4; i++) ret += (D[i] * sel[i]);
		S.insert(ret);
		sel.pop_back();
		return;
	}
	for (int i = 0; i <= rest; i++) {
		sel.push_back(i);
		solve(depth + 1, rest - i, sel);
		sel.pop_back();
	}
}

int main() {
	cin >> N;

	vector<int> sel;
	solve(0, N, sel);
	cout << S.size();
}