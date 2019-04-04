#include <iostream>
using namespace std;
typedef long long ll;
ll N, M;

ll D[1000001];


int main()
{
	ll _max = -1;
	scanf("%lld %lld", &N, &M);
	for (ll i = 0; i < N; i++)
	{
		scanf("%lld", &D[i]);
		if (_max < D[i]) _max = D[i];
	}
	ll low = 0, high = _max, sum = 0, mid;
	while (low < high)
	{
		sum = 0;
		mid = (low + high + 1) / 2;
		for (ll i = 0; i < N; i++)
			if (D[i] > mid) sum += (D[i] - mid);
		if (sum < M) high = mid - 1;
		else low = mid;
	}
	printf("%lld", low);
}