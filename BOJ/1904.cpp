#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll D[1000010];
ll N;

int main()
{
	cin >> N;
	D[1] = 1;
	D[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		D[i] = D[i - 1] + D[i - 2];
		D[i] %= 15746;
	}
	printf("%lld", D[N]);
	
}