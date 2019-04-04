#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll N, K;

int main()
{
	scanf("%lld", &N);
	vector<ll> V;
	V.push_back(0);
	for (int i = 0; i < N; i++)
	{
		ll x;
		scanf("%lld", &x);
		V.push_back(x);
	}
	scanf("%lld", &K);

	if (N == 1)
	{
		if (V[1] == K) printf("T");
		else printf("F");
		return 0;
	}

	bool flag = false;
	for (ll i = 2; i <= N; i++)
	{
		if (V[i - 1] >= (i - 1)*K && V[i] <= i * K)
		{
			flag = true;
			break;
		}
		if (V[i - 1] <= (i - 1)*K && V[i] >= i * K)
		{
			flag = true;
			break;
		}
	}
	if (flag) printf("T");
	else printf("F");
	return 0;
}