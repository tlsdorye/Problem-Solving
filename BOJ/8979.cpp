#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> P;

class ct
{
public:
	int num;
	int a, b, c;
	ct() {};
};

bool comp(ct x, ct y)
{
	if (x.a > y.a) return true;
	else if (x.a < y.a) return false;
	else
	{
		if (x.b > y.b) return true;
		else if (x.b < y.b) return false;
		else
		{
			if (x.c > y.c) return true;
			else return false;
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<ct> v(n, ct());
	for (int i = 0; i < n; i++)
		cin >> v[i].num >> v[i].a >> v[i].b >> v[i].c;
	sort(v.begin(), v.end(), comp);
	int ans = 0;
	for (int i = 0; i < v.size(); i++)
		if (k == v[i].num)
		{
			ans = i;
			break;
		}
	while (ans > 0 && v[ans].a == v[ans - 1].a && v[ans].b == v[ans - 1].b && v[ans].c == v[ans - 1].c)
		ans--;
	cout << ans+1;
}