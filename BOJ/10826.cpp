#include <iostream>
using namespace std;
typedef long long ll;

ll base = 100000000000;
ll ans[10002][1002];

int N;

ll getLength(ll n)
{
	ll ret = 0;
	while (n > 0)
	{
		n /= 10;
		ret++;
	}
	return ret;
}


int main()
{
	cin >> N;
	if (N == 0)
	{
		cout << 0;
		return 0;
	}
	ans[1][0] = 1;
	for (int i = 2; i <= N; i++)
		for (int j = 0; j <= 1000; j++)
		{
			ans[i][j] += ans[i - 1][j] + ans[i - 2][j];
			if (ans[i][j] >= base)
			{
				ans[i][j + 1]++;
				ans[i][j] -= base;
			}
		}

	int len = 0;
	bool flag = false;
	for (int i = 1001; i >= 0; i--)
	{
		len = getLength(ans[N][i]);
		if (!flag && len == 0) continue;
		if(flag) for (int j = 0; j < 11 - len; j++) printf("0");
		printf("%lld", ans[N][i]);
		flag = true;
	}
}