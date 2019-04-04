#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int T, N, M, X, Y;
int D[201];

int getBase(int n)
{
	int ret = 1;
	while (--n) ret *= 10;
	return ret;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int x = 0, y = 0, input;
		int base = getBase(M);
		int temp = base;
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &input);
			x += input * temp;
			temp /= 10;
		}
		temp = base;
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &input);
			y += input * temp;
			temp /= 10;
		}

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &D[i]);
			D[N + i] = D[i];
		}

		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			temp = base;
			int z = 0;
			for (int j = 0; j < M; j++)
			{
				z += D[i + j] * temp;
				temp /= 10;
			}
			if (x <= z && z <= y) ans++;
		}
		printf("%d\n", ans);
	}
}