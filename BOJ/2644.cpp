#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n = 100;

vector<int> e[100];
vector<bool> v(100);

void add(int a, int b)
{
	e[a].push_back(b);
	e[b].push_back(a);
}

int bfs(int a, int b)
{
	if (a == b) return 0;
	queue<int> Q;
	int level = 0;
	fill(v.begin(), v.end(), false);
	Q.push(a);
	v[a] = true;
	while (!Q.empty())
	{
		level++;
		int Qsize = Q.size();
		for (int i = 0; i < Qsize; i++)
		{
			int curr = Q.front();
			Q.pop();
			for (int j = 0; j < e[curr].size(); j++)
			{
				if (b == e[curr][j]) return level;
				if (!v[e[curr][j]]) v[e[curr][j]] = true, Q.push(e[curr][j]);
			}
		}
	}
	return -1;
}

int main()
{
	int x, y, a, b, m;
	scanf("%d %d %d %d", &n, &a, &b, &m);
	while (m--) scanf("%d %d", &x, &y), add(x - 1, y - 1);
	printf("%d", bfs(a - 1, b - 1));

	return 0;
}