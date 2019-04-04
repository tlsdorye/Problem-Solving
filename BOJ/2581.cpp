#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

vector<bool> d(10001, false);

int main()
{
	int n, m;
	cin >> n >> m;
	d[0] = true;
	d[1] = true;
	for (int i = 2; i <= 10000; i++)
	{
		if (d[i] == false)
		{
			int t = i + i;;
			while (t <= 10000)
			{
				d[t] = true;
				t += i;
			}
		}
	}
	int sum = 0, mmin = 10005;
	for (int i = n; i <= m; i++)
	{
		if (d[i] == false)
		{
			sum += i;
			if (mmin > i) mmin = i;
		}
	}
	if (sum != 0) cout << sum << "\n" << mmin;
	else cout << -1;
}