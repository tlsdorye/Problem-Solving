#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> P;

int ans = 0;
void solve(int a, int b, int c)
{
	int sum = a + b, eat;
	if (sum < c) return;
	else
	{
		eat = sum / c;
		ans += eat;
		sum  %= c;
		solve(eat, sum, c);
	}
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	solve(a, b, c);
	cout << ans;
}