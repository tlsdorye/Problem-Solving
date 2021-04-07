#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#define RED 1
#define BLUE 2
using namespace std;

typedef pair<int, int> P;

int T, V, E;
bool ans = true;
int type[20001];
vector<vector<int>> adj;
queue<P> que;

void BFS(int idx) 
{
	while (!que.empty()) que.pop();
	que.push({ idx, RED });
	type[idx] = RED;

	int level = 0;
	int qsize = 0;
	while (!que.empty()) 
	{
		P p = que.front();
		que.pop();
		int nextType;
		if (p.second == RED) nextType = BLUE;
		else nextType = RED;
		for (int np : adj[p.first]) 
		{
			if (type[np] == nextType) continue;
			else if (type[np] == 0)
			{
				type[np] = nextType;
				que.push({ np, nextType });
			}
			else
			{
				ans = false;
				return;
			}
		}

	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> V >> E;

		ans = true;
		memset(type, 0, sizeof(type));
		adj.clear();
		adj.resize(V + 1, vector<int>());

		int x, y;
		for (int i = 0; i < E; i++) {
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		for (int i = 1; i <= V; i++) {
			if (type[i] != 0) continue;
			BFS(i);
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}