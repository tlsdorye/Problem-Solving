#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int ll;

int N;
vector<ll> V;

void solve(ll x)
{
	queue<ll> que;
	for (int i = 0; i <= 9; i++) que.push(i);
	while (!que.empty())
	{
		ll curr = que.front();
		que.pop();
		ll head = curr, exp = 10;
		while (head >= 10)
		{
			head /= 10;
			exp *= 10;
		}
		for (int i = head + 1; i <= 9; i++)
		{
			ll next = i * exp + curr;
			if (next > 9876543210) continue;
			V.push_back(next);
			que.push(next);
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i <= 9; i++) V.push_back(i);
	solve(0);
	sort(V.begin(), V.end());
	if (N >= V.size()) cout << "-1";
	else cout << V[N];
}