#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, ans = 1;
		cin >> a >> b;
		while (b--)
		{
			ans *= a;
			ans %= 1000;
		}
		ans %= 10;
		if (ans == 0) ans = 10;
		cout << ans << "\n";
	}
}