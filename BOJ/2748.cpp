#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
typedef long long ll;

vector<ll> d;

ll solve(ll x)
{
	if (d[x] != -1) return d[x];
	if (x == 0 || x == 1) return d[x] = x;
	return d[x] = solve(x - 1) + solve(x - 2);
}

int main()
{
	int n;
	cin >> n;
	d.resize(n+1, -1);
	cout << solve(n);
}