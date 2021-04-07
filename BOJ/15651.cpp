#include <iostream>
using namespace std;

int N, M;
int ret[8];

void Solve(int r)
{
	if (r >= M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", ret[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		ret[r] = i;
		Solve(r + 1);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	Solve(0);
}