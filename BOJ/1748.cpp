#include <iostream>
using namespace std;
typedef long long ll;

int N, L, _L, ans, st, expo = 9;

int getLength(int n)
{
	int ret = 0;
	while (n > 0) ret++, n /= 10;
	return ret;
}

int main()
{
	cin >> N;
	_L = L = getLength(N);
	if (L == 1)
	{
		cout << N;
		return 0;
	}
	for (int i = 1; i < L; i++)
	{
		ans += expo * i;
		st += expo;
		expo *= 10;
	}
	ans += _L * (N - st);
	cout << ans;
	return 0;
}