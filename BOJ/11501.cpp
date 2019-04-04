#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int T, N;
int D[1000001];

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++) scanf("%d", &D[i]);
		int _max = 0;
		ll ans = 0;
		for (int i = N - 1; i >= 0; i--)
		{
			if (_max < D[i]) _max = D[i];
			else ans += (_max - D[i]);
		}
		printf("%lld\n", ans);
	}
}