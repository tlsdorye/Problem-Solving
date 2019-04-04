#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int _T, weight;
int N, M, T;
int S, G, H;
int dest[101];
int dist[3][2001];
vector<vector<P>> E;


void dijkstra(int s, int type)
{
	fill(dist[type], dist[type] + 2001, 987654321);
	dist[type][s] = 0;
	priority_queue<int> que;
	que.push(s);
	while (!que.empty())
	{
		int curr = que.top();
		que.pop();
		for (int i = 0; i < E[curr].size(); i++) 
		{
			int next = E[curr][i].first;
			int weight = E[curr][i].second;
			if (dist[type][next] > dist[type][curr] + weight)
			{
				dist[type][next] = dist[type][curr] + weight;
				que.push(next);
			}
		}
	}
}

int main()
{
	cin >> _T;
	while (_T--)
	{
		scanf("%d %d %d", &N, &M, &T);
		scanf("%d %d %d", &S, &G, &H);
		E.resize(N + 1, vector<P>());
		
		for (int i = 0; i < M; i++)
		{
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			E[a].push_back(make_pair(b, d));
			E[b].push_back(make_pair(a, d));
			if ((G == a && H == b) || (G == b && H == a)) weight = d;
		}
		for (int i = 0; i < T; i++) scanf("%d", &dest[i]);
		dijkstra(S,0);
		dijkstra(G, 1);
		dijkstra(H, 2);

		vector<int> ans;
		for (int i = 0; i < T; i++)
		{
			if (dist[0][G] + weight + dist[2][dest[i]] <= dist[0][dest[i]]) ans.push_back(dest[i]);
			else if (dist[0][H] + weight + dist[1][dest[i]] <= dist[0][dest[i]]) ans.push_back(dest[i]);
		}
		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		printf("\n");

		E.clear();
	}
	return 0;
}