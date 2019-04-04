#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll N, M;
ll degree[32001];

vector<vector<ll>> E;
queue<ll> que;

void solve()
{
	while (!que.empty())
	{
		ll curr = que.front();
		printf("%lld ", curr);
		que.pop();
		for (int i = 0; i < E[curr].size(); i++)
		{
			ll next = E[curr][i];
			degree[next]--;
			if (degree[next] == 0) que.push(next);
		}
	}
}

int main()
{
	scanf("%lld %lld", &N, &M);
	E.resize(N + 1, vector<ll>());
	for (int i = 1; i <= M; i++)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		E[x].push_back(y);
		degree[y]++;
	}

	for (int i = 1; i <= N; i++)
		if (degree[i] == 0) que.push(i);

	solve();
}