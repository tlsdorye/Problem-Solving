#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int N, L, ans;
vector<P> V;

int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		V.push_back({ x,y });
	}
	sort(V.begin(), V.end());
	int start = 0, count = 0;
	for (int i = 0; i < V.size(); i++)
	{
		start = max(V[i].first, start);
		count = (V[i].second - start + (L - 1)) / L;
		ans += count;
		start += count * L;	
	}
	printf("%d\n", ans);
}
