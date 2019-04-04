#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#define INF 987654321
typedef long long ll;
using namespace std;

int solve(int a, int b, int c)
{
	if (a == b && b == c) return 10000 + a * 1000;
	else if (a != b && b != c && c != a) return max(a, max(b, c)) * 100;
	else
	{
		if (a == b) return 1000 + a * 100;
		else if (b == c) return 1000 + b * 100;
		else return 1000 + c * 100;
	}
}

int main() {
	int n, a, b, c, ans = 0;
	cin >> n;
	while(n--)
	{
		cin >> a >> b >> c;
		ans = max(ans, solve(a, b, c));
	}
	cout << ans;
}