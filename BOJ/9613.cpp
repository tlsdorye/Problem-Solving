#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;

ll arr[101];

ll getGCD(ll x, ll y)
{
	if (x%y == 0) return y;
	return getGCD(y, x%y);
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		sort(arr, arr + N, greater<int>());
		ll ans = 0;
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++) 
				ans += getGCD(arr[i], arr[j]);
		cout << ans << "\n";
	}
}
