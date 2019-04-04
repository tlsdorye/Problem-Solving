#include <iostream>
#include <cstring>

using namespace std;

int d[1002];

int solve(int i)
{
	if (d[i] != -1) return d[i];
	if (i == 0) return d[i] = 0;
	if (i == 1) return d[i] = 1;
	d[i] = solve(i - 1) + solve(i - 2);
	return d[i] % 10007;
}

int main()
{
	int n;
	cin >> n;
	memset(d, -1, sizeof(d));
	cout << solve(n+1);

	return 0;
}