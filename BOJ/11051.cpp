#include <iostream>
using namespace std;
typedef long long ll;

ll D[1001][1001];

int N, K;

void getPascal(int x)
{
	for (int i = 0; i <= x; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i) D[i][j] = 1;
			else D[i][j] = (D[i - 1][j - 1] + D[i - 1][j]) % 10007;
		}
}

void print()
{
	printf("--Pascal--\n");
	for (int i = 0; i <= N; i++,printf("\n"))
		for (int j = 0; j <= i; j++) printf("%d ", D[i][j]);
}


int main()
{
	cin >> N >> K;
	getPascal(N);
	printf("%d", D[N][K]);
}