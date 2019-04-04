#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long int ll;

int N, M, V;
vector<vector<int>> D;
bool isVisit[1001];

void DFS(int s)
{
	if (isVisit[s]) return;
	isVisit[s] = true;
	cout << s << " ";
	for (int i = 0; i < D[s].size(); i++) DFS(D[s][i]);
}

void BFS(int s)
{
	queue<int> que;
	que.push(s);
	isVisit[s] = true;
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();
		cout << cur << " ";
		for (int i = 0; i < D[cur].size(); i++)
		{
			int next = D[cur][i];
			if (!isVisit[next]) isVisit[next] = true, que.push(next);
		}
	}
}

int main()
{
	cin >> N >> M >> V;
	D.resize(N + 1, vector<int>());
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		D[x].push_back(y);
		D[y].push_back(x);
	}

	for (int i = 0; i < N; i++) sort(D[i].begin(), D[i].end());

	DFS(V);
	cout << endl;
	memset(isVisit, false, sizeof(isVisit));
	BFS(V);
}