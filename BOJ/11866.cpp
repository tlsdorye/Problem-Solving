#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#define INF 987654321
typedef long long ll;
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	deque<int> d;
	for (int i = 1; i <= n; i++) d.push_back(i);
	cout << "<";
	while (!d.empty())
	{
		int t = m - 1, x;
		while (t--)
		{
			x = d.front();
			d.push_back(x);
			d.pop_front();
		}
		x = d.front();
		d.pop_front();
		cout << x;
		if (!d.empty()) cout << ", ";
	}
	cout << ">";
}
