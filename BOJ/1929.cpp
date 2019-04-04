#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int n, m;
vector<int> d;
void solve(int x)
{
	int t = x + x;
	while (t <= m)
	{
		d[t]++;
		t += x;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	d.resize(m+1, 0);
	for (int i = 2; i <= m; i++)
	{
		if (d[i] == 0)
		{
			solve(i);
			if (i >= n) printf("%d\n", i);
		}
	}
	return 0;
}