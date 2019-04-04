#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
typedef long long ll;
using namespace std;

int main() {
	int t, n;
	ll f[68] = {0};
	for (int i = 0; i < 68; i++) {
		if (i < 2) f[i] = 1;
		else if (i == 2) f[i] = 2;
		else if (i == 3) f[i] = 4;
		else f[i] = f[i - 1] + f[i - 2] + f[i - 3] + f[i - 4];
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << f[n] << endl;
	}
}