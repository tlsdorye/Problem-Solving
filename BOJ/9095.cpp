#include <iostream>
using namespace std;

int solve(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	return solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main()
{
	int test_case;
	cin >> test_case;
	for (int T = 0; T < test_case; T++)
	{
		int n;
		cin >> n;
		cout << solve(n) << "\n";
	}
}
