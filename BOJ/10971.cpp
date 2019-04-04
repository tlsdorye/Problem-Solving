#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int n, start, ans = INF;
vector<vector<P>> adj;

void solve(int x,int y, vector<bool> visit) // 현재 위치,현재까지 경로값, 방문 정보
{
	int curr = x, path = y;
	vector<bool> v(visit);
	v[curr] = true;
	bool flag = false;
	for (int i = 0; i < v.size(); i++)
	{
		if (!v[i])
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		for (int i = 0; i < adj[curr].size(); i++)
			if (adj[curr][i].first == start) ans = min(ans, path + adj[curr][i].second);
	}
	else
	{
		int next, cost;
		for (int i = 0; i < adj[curr].size(); i++)
		{
			next = adj[curr][i].first;
			cost = adj[curr][i].second;
			if (!v[next])
				solve(next, path+cost, v);
		}
	}
}

int main()
{
	cin >> n;
	adj.resize(n, vector<P>());
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			if (x != 0) adj[i].push_back(make_pair(j, x));
		}
	vector<bool> temp(n, false);
	for (int i = 0; i < n; i++)
	{
		start = i;
		solve(i, 0, temp);
	}
	cout << ans;
}