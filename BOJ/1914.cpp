#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int N;
deque<int> que;

void solve(int x, int y, int n)
{
	if (n == 1)
	{
		printf("%d %d\n", x, y);
		return;
	}
	solve(x, 6 - x - y, n - 1);
	printf("%d %d\n", x, y);
	solve(6 - x - y, y, n - 1);
	return;
}

void calc(ll n)
{
	if (n >= N)
	{
		int curr = que.front();
		que.pop_front();
		que.push_front(curr - 1);
		return;
	}
	ll qSize = que.size();
	int F = 0, S = 0;
	for (int i = 0; i < qSize; i++)
	{
		int curr = que.front();
		que.pop_front();
		int next = curr * 2;
		next += F;
		F = 0;
		if (next >= 10) F++;
		S = next % 10;
		que.push_back(S);
	}
	if (F != 0) que.push_back(F);
	calc(n + 1);
}

int main()
{
	
	scanf("%d", &N);
	que.push_back(2);
	calc(1);
	int qSize = que.size();
	for (int i = 0; i < qSize; i++)
	{
		printf("%d", que.back());
		que.pop_back();
	}
	printf("\n");
	if (N <= 20) solve(1, 3, N);
}