#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
int D[100001];

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++) scanf("%d", &D[i]);
		sort(D, D + N);
		int ans = 0;
		for (int i = 2; i < N; i += 2) ans = max(ans, D[i] - D[i - 2]);
		for (int i = 3; i < N; i += 2) ans = max(ans, D[i] - D[i - 2]);
		ans = max(ans, D[1] - D[0]);
		ans = max(ans, D[N - 1] - D[N - 2]);
		printf("%d\n", ans);
	}
}