#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll T, N, K, W;

ll V[1001][2], Degree[1001];
vector<vector<ll>> E;

queue<ll> que;

void solve()
{
	vector<ll> TSort;
	while(!que.empty())
	{
		ll curr = que.front();
		TSort.push_back(curr);
		que.pop();
		for (int i = 0; i < E[curr].size(); i++)
		{
			ll next = E[curr][i];
			Degree[next]--;
			if (Degree[next] == 0) que.push(next);
		}
	}

	for (int i = 0; i < TSort.size(); i++)
	{
		ll curr = TSort[i];
		for (int j = 0; j < E[curr].size(); j++)
		{
			ll next = E[curr][j];
			V[next][1] = max(V[next][1], V[next][0] + V[curr][1]);
		}
		if (curr == W)
		{
			printf("%lld\n", V[curr][1]);
			return;
		}
	}
}

int main()
{
	scanf("%lld", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%lld%lld", &N, &K);
		E.resize(N + 1, vector<ll>());
		
		for (int i = 1; i <= N; i++)
		{
			scanf("%lld", &V[i][0]);
			V[i][1] = V[i][0];
		}

		for (int i = 1; i <= K; i++)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			E[x].push_back(y);
			Degree[y]++;
		}
		scanf("%lld", &W);

		for (int i = 1; i <= N; i++)
			if (Degree[i] == 0) que.push(i);

		solve();
		E.clear();
		memset(V, 0, sizeof(V));
		memset(Degree, 0, sizeof(Degree));
	}
}

