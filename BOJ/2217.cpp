#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N;
ll D[100001];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> D[i];
	sort(D, D + N);
	ll ans = -1;
	for (int i = 0; i < N; i++)
		ans = max(ans, (N - i)*D[i]);
	cout << ans;
}