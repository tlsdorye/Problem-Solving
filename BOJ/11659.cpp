#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

ll N, M;

ll D[100001], S[100001];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &D[i]);
		S[i] = S[i - 1] + D[i];
	}
	for (int i = 0; i < M; i++)
	{
		ll x, y;
		scanf("%lld %lld", &x, &y);
		printf("%lld\n", S[y] - S[x - 1]);
	}
}
