#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

ll base = 1, B, ans = 0;
string N;


int main()
{
	cin >> N >> B;
	for (int i = N.size() - 1; i >= 0; i--)
	{
		if ('0' <= N[i] && N[i] <= '9') ans += (N[i] - '0')*base;
		else ans += (N[i] - 'A' + 10)*base;
		base *= B;
	}
	cout << ans;
}
