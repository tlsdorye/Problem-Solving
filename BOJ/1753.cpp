#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
vector<vector<P>> adj;
int v, e, s;

vector<int> getd(int s)
{
	vector<int> dist(v + 1, INF);
	dist[s] = 0;
	priority_queue<P, vector<P>, greater<P> > que;
	que.push(make_pair(0, s));
	while (!que.empty())
	{
		int cost = que.top().first;
		int curr = que.top().second;
		que.pop();
		if (dist[curr] < cost) continue;
		for (int i = 0; i < adj[curr].size(); i++)
		{
			int nextcost = adj[curr][i].second;
			int next = adj[curr][i].first;
			if (dist[next] > cost + nextcost)
				dist[next] = cost + nextcost, que.push(make_pair(dist[next], next));
		}
	}
	return dist;
}

int main()
{

	cin >> v >> e >> s;
	adj.resize(v + 1);
	for (int i = 0; i < e; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back(make_pair(b,w));
	}
	vector<int> dist = getd(s);
	for (int i = 1; i < dist.size(); i++)
	{
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}