#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, ans = -2000000000;
string expr;
int arr[20];

void Solve(int ret, int idx)
{
	if (idx >= N)
	{
		ans = max(ans, ret);
		return;
	}

	if (expr[idx] == '+')
	{
		if(idx + 2 < N)
			Solve(ret + arr[idx + 2], idx + 4);
		Solve(ret + (expr[idx + 1] - '0'), idx + 2);
	}
	else if (expr[idx] == '-')
	{
		if (idx + 2 < N)
			Solve(ret - arr[idx + 2], idx + 4);
		Solve(ret - (expr[idx + 1] - '0'), idx + 2);
	}
	else if (expr[idx] == '*')
	{
		if (idx + 2 < N)
			Solve(ret * arr[idx + 2], idx + 4);
		Solve(ret * (expr[idx + 1] - '0'), idx + 2);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> expr;

	for (int i = 1; i < N; i += 2)
	{
		if (expr[i] == '+') arr[i] = (expr[i - 1] - '0') + (expr[i + 1] - '0');
		else if (expr[i] == '-') arr[i] = (expr[i - 1] - '0') - (expr[i + 1] - '0');
		else if (expr[i] == '*') arr[i] = (expr[i - 1] - '0') * (expr[i + 1] - '0');
	}
	Solve(expr[0] - '0', 1);
	cout << ans;

}