#include <iostream>
#include <cmath>
using namespace std;

int N, S[51];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i];
	
	if (N == 1) cout << "A";
	else if (N == 2)
	{
		if (S[0] == S[1]) cout << S[0];
		else cout << "A";
	}
	else 
	{
		int a = 1, b = 0;
		int x1 = S[0], x2 = S[1], x3 = S[2];
		if (x1 != x2)
		{
			a = (x3 - x2) / (x2 - x1);
			b = x2 - x1 * a;
		}
		bool flag = true;
		for (int i = 0; i < N - 1; i++)
			if (S[i] * a + b != S[i + 1])
			{
				flag = false;
				break;
			}
		if (flag) cout << S[N - 1] * a + b;
		else cout << "B";
	}
}