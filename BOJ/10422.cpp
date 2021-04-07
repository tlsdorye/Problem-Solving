#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


ll T, L, MOD = 1000000007;
ll D[5001][5001];

ll solve(int l, int r) {
	if (l < r) return 0;
	if (l < 0 || r < 0) return 0;
	if (l == 0 && r == 0) return 1;
	if (D[l][r] != -1) return D[l][r];

	ll ret = (solve(l - 1, r) + solve(l, r - 1)) % MOD;
	return D[l][r] = ret;
}

int main() {
	cin >> T;
	fill(&D[0][0], &D[5000][5001], -1);
	
	for (int tc = 1; tc <= T; tc++) {

		cin >> L;

		ll ANS = 0;
		if (L % 2 == 0) ANS = solve(L / 2, L / 2);

		cout << ANS << "\n";
	}
}