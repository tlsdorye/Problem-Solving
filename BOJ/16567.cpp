#include <iostream>
using namespace std;

int D[1000010];

int N, M, ans = 0;
bool flag = false;

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &D[i]);
		if (D[i] == 1 && !flag) flag = true;
		else if (D[i] == 0 && flag) flag = false, ans++;
	}
	if (flag) ans++;

	int x, y;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d", &x);
		if (x == 0) printf("%d\n", ans);
		else if (x == 1)
		{
			scanf("%d", &y);
			if (D[y] == 1) continue;
			else
			{
				D[y] = 1;
				if (D[y - 1] == 0 && D[y + 1] == 0) ans++;
				else if (D[y - 1] == 1 && D[y + 1] == 1) ans--;
			}
		}
	}
}