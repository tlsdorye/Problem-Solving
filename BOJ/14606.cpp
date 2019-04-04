#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int ans = 0;

void solve(int x) {
	if (x == 0) return;
	int max = 0, a = 0, b = 0;
	for (int i = 0; i < x; i++) {
		if (max < i*(x - i)) {
			max = i*(x - i);
			a = i;
			b = x - i;
		}
	}
	ans += max;
	solve(a);
	solve(b);
}

int main() {
	int n;
	cin >> n;
	solve(n);
	cout << ans;
}
