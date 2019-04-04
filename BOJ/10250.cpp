#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef long long ll;

vector<int> d;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int h, w, n;
		cin >> h >> w >> n;
		int x, y;
		if (n%h == 0)
		{
			x = h;
			y = n / h;
		}
		else
		{
			x = n%h;
			y = n / h + 1;
		}
		if (y < 10) cout << x << "0" << y << "\n";
		else cout << x << y <<"\n";
	}
}