#include <iostream>
#include <cstring>

using namespace std;

int d[1010];

int solve(int i)
{
	if (d[i] != -1) return d[i];
	return d[i] = (solve(i - 1) + 2 * solve(i - 2)) % 10007;
}

int main()
{
	int n;
	cin >> n;
	memset(d, -1, sizeof(d));
	d[1] = 1, d[2] = 3;
	cout << solve(n);
	return 0;
}