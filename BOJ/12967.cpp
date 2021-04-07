#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll N, K;
ll A[2001];
map<int, vector<int>> M;

void get_divisor(int idx) {
	ll x = sqrt(A[idx]);
	for (int i = 1; i <= x; i++) {
		if (A[idx] % i == 0) {
			M[i].push_back(idx);
			if(i != A[idx] / i) M[A[idx] / i].push_back(idx);
		}
	}
}

ll get_gcd(ll x, ll y) {
	if (x % y == 0) return y;
	return get_gcd(y, x % y);
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	for (int i = 0; i < N; i++) get_divisor(i);

	ll ANS = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			ll g = K / get_gcd(K, A[i] * A[j]);
			ANS += (M[g].end() - upper_bound(M[g].begin(), M[g].end(), j));
		}

	cout << ANS;
}	