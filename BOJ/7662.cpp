#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#include <map>
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		ll x;
		char c;
		cin >> k;
		multimap<ll, ll> m;

		while (k--)
		{
			cin >> c >> x;
			if (c == 'I') m.insert(make_pair(x,x));
			else if (c == 'D' && !m.empty())
			{
				if (x == 1) m.erase(--m.end());
				else if (x == -1) m.erase(m.begin());
			}

		}
		if (m.empty()) cout << "EMPTY" << endl;
		else cout << (--m.end())->first << " " << m.begin()->first << endl;
	}
}