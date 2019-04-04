#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int N, ans;

void solve(int n, int depth)
{
	if (n <= 2) return;
	if (depth == 0) 
	{
		for (int i = 2; i <= n; i += 2)
			solve(n - i, depth + 1);
	}
	else if (depth == 1)
	{
		for (int i = 1; i <= n; i++)
			if (n - 2 * i >= 2) ans++;
	}
}

int main()
{
	cin >> N;
	solve(N,0);
	printf("%d\n", ans);
}
