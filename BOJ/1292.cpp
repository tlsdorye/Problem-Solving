#include <iostream>
using namespace std;

int A, B;
int D[1100];

void solve()
{
	int cnt = 1;
	for (int i = 0; i < 1100; i++)
	{
		int j = 0;
		for (; j < cnt && i + j < 1100; j++)
			D[i + j] = cnt;
		i += (j - 1);
		cnt++;
	}
}

int main()
{
	cin >> A >> B;
	solve();
	int sum = 0;
	for (int i = A - 1; i < B; i++) sum += D[i];
	cout << sum;
}