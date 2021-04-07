#include <iostream>
using namespace std;

int N, M;
int ret[8];

void Solve(int r, int idx)
{
	if (r >= M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", ret[i]);
		printf("\n");
		return;
	}
	for (int i = idx; i <= N; i++)
	{
		ret[r] = i;
		Solve(r + 1, i);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	Solve(0, 1);
}