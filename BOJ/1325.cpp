#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> P;
int N, M;

vector<vector<int>> E;
vector<P> hN;
vector<int> ans;

int solve(int s)
{
	int ret = 0;
	bool visit[10001] = {};
	queue<int> que;
	que.push(s);
	visit[s] = true;
	while (!que.empty())
	{
		int top = que.front();
		que.pop();
		ret++;
		for (int i = 0; i < E[top].size(); i++)
		{
			int next = E[top][i];
			if (!visit[next])
			{
				visit[next] = true;
				que.push(next);
			}
		}
	}
	return ret;
}

int main()
{
	cin >> N >> M;
	E.resize(N + 1, vector<int>());
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		E[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		hN.push_back({ solve(i), i });

	sort(hN.begin(), hN.end());
	int Best = hN[hN.size() - 1].first;

	for (int i = hN.size() - 1; i >= 0; i--)
	{
		if (Best == hN[i].first) ans.push_back(hN[i].second);
		else break;
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
}