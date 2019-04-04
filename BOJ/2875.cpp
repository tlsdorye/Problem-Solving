#include <iostream>
using namespace std;

int N, M, K, ans, R;

int main()
{
	cin >> N >> M >> K;
	if (N >= M * 2)
	{
		ans = M;
		R = N - M * 2;
	}
	else
	{
		ans = N / 2;
		R = M - N / 2 + N % 2;
	}
	if (R >= K) cout << ans;
	else
	{
		int temp = K - R;
		ans -= temp / 3;
		if (temp % 3 != 0) ans -= 1;
		cout << ans;
	}
	return 0;
}