#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, a, b, ans;
int D[3000001];
int INF = 987654321;
queue<int> que;

int main()
{
	cin >> N >> a >> b;
	for (int i = 1; i <= N; i++) D[i] = INF;
	a++, b++;

	que.push(0);
	while (!que.empty())
	{
		int curr = que.front();
		que.pop();
		if (curr == N) break;
		if (curr > N) continue;
		if (D[curr] + 1 < D[curr + 1])
		{
			D[curr + 1] = D[curr] + 1;
			if (curr + 1 == N) break;
			que.push(curr + 1);
		}
		if (D[curr] + a < D[curr + a])
		{
			D[curr + a] = D[curr] + 1;
			if (curr + a == N) break;
			que.push(curr + a);
		}
		if (D[curr] + b < D[curr + b])
		{
			D[curr + b] = D[curr] + 1;
			if (curr + b == N) break;
			que.push(curr + b);
		}
	}
	printf("%d\n", D[N]);
}