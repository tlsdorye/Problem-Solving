#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct Graph
{
	int v;
	vector< vector<int> > edge;
	vector<bool> visited;

	Graph() {};

	Graph(int n)
	{
		v = n;
		edge.resize(n);
		visited.resize(n);
	}
	void add_edge(int u, int v)
	{
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int bfs(int a, int b)
	{
		fill(visited.begin(), visited.end(), false);
		queue<int> q;
		int flag = 0, level = 0;

		q.push(a);
		visited[a] = true;
		while (!q.empty())
		{
			int Qsize = q.size();
			level++;
			for (int k = 0; k < Qsize; k++)
			{
				int curr = q.front();
				q.pop();
				for (int i = 0; i < edge[curr].size(); i++)
				{
					if (b == edge[curr][i])
					{
						flag++;
						break;
					}
					if (!visited[edge[curr][i]]) visited[edge[curr][i]] = true, q.push(edge[curr][i]);
				}
				if (flag) break;
			}
			if (flag) break;
		}
		if (flag) return level;
		return -1;
	}
};


int main()
{
	int a, b, n, m, x, y;
	scanf("%d %d %d %d", &a, &b, &n, &m);
	if (a == b)	printf("0");
	else
	{
		Graph g(n);
		while (m--) scanf("%d %d", &x, &y), g.add_edge(x - 1, y - 1);
		printf("%d", g.bfs(a - 1, b - 1));
	}
	return 0;
}