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

int n, m, x;
vector<vector<pair<int, int>>> map;
vector < vector<pair<int, int>>> rmap;

vector<int> getdist(int s)
{
	vector<int> dist(n+1, INF);
	dist[s] = 0;
	priority_queue<pair<int, int>> que;
	que.push(make_pair(s, 0));

	while (!que.empty())
	{
		int curr = que.top().first;
		int cost = que.top().second;
		que.pop();
		if (dist[curr] < cost) continue;
		for (int i = 0; i < map[curr].size(); i++)
		{
			int next = map[curr][i].first, nextcost = map[curr][i].second;
			if (dist[next] > cost + nextcost)
				dist[next] = cost + nextcost, que.push(make_pair(next, dist[next]));
		}
	}
	
	return dist;
}

int main()
{
	cin >> n >> m >> x;
	map.resize(n + 1);
	rmap.resize(n + 1);

	int a, b, t;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> t;
		map[a].push_back(make_pair(b, t));
		rmap[b].push_back(make_pair(a, t));
	}
	vector<int> back_dist = getdist(x);
	map.clear();
	map.assign(rmap.begin(), rmap.end());
	vector<int> go_dist = getdist(x);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (ans < back_dist[i] + go_dist[i]) ans = back_dist[i] + go_dist[i];
	cout << ans;
}
