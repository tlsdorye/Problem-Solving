#include <iostream>
using namespace std;

bool check[3][31];
int N, ans = 0;

void solve(int col)
{
	if (col == N) ans++;
	for (int i = 0; i < N; i++)
	{
		if (check[0][i]) continue;
		if (check[1][col + i]) continue;
		if (check[2][N + col - i]) continue;
		
		check[0][i] = true;
		check[1][col + i] = true;
		check[2][N + col - i] = true;

		solve(col + 1);

		check[0][i] = false;
		check[1][col + i] = false;
		check[2][N + col - i] = false;
	}
}

int main()
{
	cin >> N;
	solve(0);
	cout << ans;
}