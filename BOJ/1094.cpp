#include <iostream>
using namespace std;

int t,ans = 0;

void solve()
{
	if (t % 2 == 1) ans++;
	t /= 2;
	if (t != 0) solve();
}

int main() {
	cin >> t;
	solve();
	cout << ans;
}