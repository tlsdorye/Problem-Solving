#include <iostream>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll>> que;

int K, N;
ll D[101];

int main()
{
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		scanf("%lld", &D[i]);
		que.push(D[i]);
	}
	ll curr = 0;
	for (int i = 1; i < N; i++)
	{
		curr = que.top();
		que.pop();
		for (int j = 0; j <= K; j++)
		{
			que.push(D[j] * curr);
			if (curr % D[j] == 0) break;
		}
	}
	cout << que.top();
}
