#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <utility>
typedef long long ll;
using namespace std;

void solve(int x,int y) {
	int a = x, b = y, G = 0;
	if (a > b) swap(a, b);
	for (int i = 1; i <= b; i++) {
		if (a%i == 0 && b%i == 0 && G < i) G = i;
	}
	cout << (a / G)*(b / G)*G << " " << G << endl;
}

int main() {
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		solve(x, y);
	}
}