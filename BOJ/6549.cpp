#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <utility>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll H[100002];
stack<P> S;

int main()
{
	ll N;
	scanf("%lld", &N);
	while (N != 0)
	{
		for (int i = 1; i <= N; i++) scanf("%lld", &H[i]);

		ll ANS = 0;
		while (!S.empty()) S.pop();
		for (int i = 1; i <= N + 1; i++)
		{
			if (S.empty() || H[i] > S.top().first) S.push({ H[i], i });
			else
			{
				P p = S.top();
				S.pop(), i--;
				if (S.empty()) ANS = max(ANS, p.first * i);
				else ANS = max(ANS, p.first * (i - S.top().second));
			}
		}
		printf("%lld\n", ANS);
		memset(H, 0, sizeof(H));
		scanf("%lld", &N);
	}
}