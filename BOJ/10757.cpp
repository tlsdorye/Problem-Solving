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
	string n, m;
	cin >> n >> m;
	if (n.size() < m.size()) swap(n, m);
	vector<int> d(n.size() + 1, -1);
	reverse(n.begin(),n.end());
	reverse(m.begin(), m.end());
	int a, b, c = 0;
	for (int i = 0; i < n.size(); i++)
	{
		if (i < m.size())
		{
			int a = n[i] - '0';
			int b = m[i] - '0';
			d[i] = (a + b + c) % 10;
			c = (a + b + c) / 10;
		}
		else
		{
			d[i] = ((n[i]-'0') + c)%10;
			c = (n[i] - '0' + c) / 10;
		}
	}
	if (c == 1) d[n.size()] = 1;
	for (int i = d.size()-1; i >= 0; i--) if (d[i] != -1) cout << d[i];
}