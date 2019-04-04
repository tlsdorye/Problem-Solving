#include <iostream>
using namespace std;
typedef long long int ll;

ll A, B, C, R;

ll solve(int a, int b, int c)
{
	if (b == 1) return R;
	ll ret = solve(a, b / 2, c);
	if (b % 2 == 0) return (ret*ret) % c;
	return (((ret*ret) % c)*R) % c;
}

int main()
{
	cin >> A >> B >> C;
	R = A % C;
	cout << solve(A, B, C);
}