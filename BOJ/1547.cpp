#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int main() {
	int n, d[3] = { 1,0,0 };
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		swap(d[x-1], d[y-1]);
	}
	for (int i = 0; i < 3; i++) {
		if (d[i] == 1) cout << i + 1;
	}
}