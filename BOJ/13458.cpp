#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int n, b, c;
vector<ll> a;

ll solve() {
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		a[i] -= b;
		if (a[i] <= 0) ans++;
		else {
			if (a[i] % c == 0) ans = ans + a[i] / c + 1;
			else ans = ans + a[i] / c + 2;
		}
	}
	return ans;
}

int main() {
	ll tmp;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tmp);
		a.push_back(tmp);
	}
	cin >> b >> c;
	cout << solve();
	return 0;
}