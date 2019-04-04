#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;
ll D[4001][4];
ll A[16000001], B[16000001];
ll ans = 0;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%lld %lld %lld %lld", &D[i][0], &D[i][1], &D[i][2], &D[i][3]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			A[i*N + j] = D[i][0] + D[j][1];
			B[i*N + j] = D[i][2] + D[j][3];
		}

	sort(A, A + (N * N));
	sort(B, B + (N * N));

	int s = 0, e = N * N - 1;
	while (s < N * N && e >= 0)
	{
		if (A[s] + B[e] == 0)
		{
			ll x = 0, y = 0;
			while (A[s] + B[e] == 0 && s < N*N) x++, s++;
			while (A[s - 1] + B[e] == 0 && e >= 0) y++, e--;
			ans += x * y;
		}
		else if (A[s] + B[e] < 0) s++;
		else e--;
	}
	cout << ans;
}
