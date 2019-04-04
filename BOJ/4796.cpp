#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll L, P, V;

int main()
{
	ll test_case = 1;
	cin >> L >> P >> V;
	while (L != 0 && P != 0 && P != 0)
	{
		ll ans = L * (V / P);
		if (V%P >= L) ans += L;
		else ans += V%P;
		printf("Case %lld: %lld\n", test_case++, ans);
		cin >> L >> P >> V;
	}
}