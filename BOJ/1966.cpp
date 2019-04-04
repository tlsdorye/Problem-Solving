#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll N, M, K;



int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> M >> K;
		vector<ll> D, V;
		for (int j = 0; j < M; j++)
		{
			ll x;
			scanf("%lld", &x);
			D.push_back(x);
			V.push_back(x);
		}
		sort(V.begin(), V.end());
		ll idx = V.size() - 1, jdx = 0, ans = 0;
		while (1)
		{
			if (D[jdx] == V[idx])
			{
				ans++;
				if (jdx == K)
				{
					printf("%lld\n", ans);
					break;
				}
				idx--;
				jdx++;
			}
			else jdx++;
			if (jdx == D.size()) jdx = 0;
		}
	}
}