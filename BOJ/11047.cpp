#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, t, ans = 0;
	cin >> n >> k;
	vector<int> coin(n);
	for (int i = 0; i < n; i++) scanf("%d", &coin[i]);

	for (int i = n - 1; i >= 0; i--) {
		if (k >= coin[i]) {
			ans += k / coin[i];
			k %= coin[i];
		}
	}
	cout << ans;
	return 0;
}