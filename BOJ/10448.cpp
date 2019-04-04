#include <iostream>
#include <set>
using namespace std;
typedef long long int ll;

set<ll> set1, set2, set3;

int main()
{
	ll n = 1, k, t;
	cin >> k;
	while ((t = n*(n + 1) / 2) <= 1000)
	{
		set1.insert(t);
		n++;
	}
	for (auto i : set1)
		for (auto j : set1)
		{
			if (i + j > 1000)break;
			set2.insert(i + j);
		}
	for (auto i : set1)
		for (auto j : set2)
		{
			{
				if (i + j > 1000)break;
				set3.insert(i + j);
			}
		}
	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		if (set3.find(x) != set3.end()) cout << "1\n";
		else cout << "0\n";
	}
}