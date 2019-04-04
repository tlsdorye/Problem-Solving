#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#include <map>
#include <functional>
#include <set>
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	set<int> a;
	int t, n, m;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> t, a.insert(t);
	cin >> m;
	vector<int> b(m, 0);
	for (int i = 0; i < m; i++) cin >> b[i];
	set<int>::iterator it;
	for (int i=0;i<m;i++)
	{
		it = a.find(b[i]);
		if (it != a.end()) printf("1\n");
		else printf("0\n");
	}
}