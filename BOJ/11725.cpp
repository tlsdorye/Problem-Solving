#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int P[100001];
bool visit[100001];
vector<vector<int>> T;
queue<int> que;

int main()
{
	cin >> N;
	T.resize(N + 1, vector<int>());
	for (int i = 1; i < N; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		T[x].push_back(y);
		T[y].push_back(x);
	}
	que.push(1);
	while (!que.empty())
	{
		int curr = que.front();
		que.pop();
		visit[curr] = true;
		for (int i = 0; i < T[curr].size(); i++)
		{
			int next = T[curr][i];
			if (visit[next]) continue;
			que.push(next);
			visit[next] = true;
			P[next] = curr;
		}
	}
	for (int i = 2; i <= N; i++)
		printf("%d\n", P[i]);
}