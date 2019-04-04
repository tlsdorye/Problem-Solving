#include <iostream>
#include <algorithm>
using namespace std;

int N, x, y;

void solve(int n)
{
	if (n == 0) return;
	solve(n - 1);
	while (n % 2 == 0) x++, n /= 2;
	while (n % 5 == 0) y++, n /= 5;
}


int main()
{
	cin >> N;
	solve(N);
	cout << min(x, y);
}