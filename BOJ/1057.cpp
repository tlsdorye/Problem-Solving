#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

ll N, A, B, ans = 0;

int main()
{
	cin >> N >> A >> B;
	while (A != B)
	{
		ans++;
		A = (A + 1) / 2;
		B = (B + 1) / 2;
	}
	cout << ans;
}
