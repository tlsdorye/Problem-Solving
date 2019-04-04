#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <string>
#define MAX 200001
typedef long long ll;
using namespace std;

bool cmp(pair<string, int> &p, pair<string, int> &q)
{
	return p.second < q.second;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<pair<string, int>> school(n);
		for (int i = 0; i < n; i++)
			cin >> school[i].first >> school[i].second;
		sort(school.begin(), school.end(), cmp);
		cout << school[n - 1].first << endl;
	}
}