#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e7 + 19;
ll C[301][301];

void Init() {
	for (int i = 0; i <= 300; i++) C[i][0] = 1;
	for (int i = 1; i <= 300; i++)
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
}


int solution(vector<vector<int>> a) {
	int N = a.size();
	int M = a[0].size();
	Init();

	vector<ll> num(M + 1, 0);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			num[j + 1] += a[i][j];

	vector<vector<ll>> dp(M + 1, vector<ll>(N + 1, 0));
	dp[1][N - num[1]] = C[N][num[1]];

	for (int j = 1; j <= M; j++) {
		int one = num[j];
		for (int er = 0; er <= N; er++) {
			for (int k = 0; k <= one; k++) {
				int ner = (er - k) + (one - k);
				if (er < k || ner < 0 || ner > N) continue;
				ll x = (C[er][k] * C[N - er][one - k]) % MOD;
				dp[j][ner] += (dp[j - 1][er] * x) % MOD;
				dp[j][ner] %= MOD;
			}
		}
	}
	return dp[M][N];
}