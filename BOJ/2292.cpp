#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int n;

int main()
{
	scanf("%d", &n);
	int ans = 1, i = 6;
	while (n > 1)
	{
		n -= i;
		ans++;
		i += 6;
	}
	printf("%d", ans);
}