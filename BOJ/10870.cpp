#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int n;
vector<int> d;


int solve(int n)
{
	if (d[n] != -1) return d[n];
	else d[n] = solve(n - 1) + solve(n - 2);
	return d[n];
}

int main()
{
	cin >> n;
	d.resize(n+1, -1);
	d[0] = 0, d[1] = 1;
	cout << solve(n);
}