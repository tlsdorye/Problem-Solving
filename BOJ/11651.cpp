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

bool cmp(pair<int, int> &p, pair<int, int> &q)
{
	if (p.second < q.second) return true;
	else if (p.second > q.second) return false;
	else
	{
		if (p.first < q.first) return true;
		else return false;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;
	sort(p.begin(), p.end(), cmp);
	for (int i = 0; i < n; i++) printf("%d %d\n", p[i].first, p[i].second);
}
