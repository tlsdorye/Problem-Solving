#include <iostream>
#include <string>
using namespace std;

int D[26][50010] = { 0 };

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 1; j < s.length() + 1; j++)
		{
			if (s[j - 1] - 'a' == i) D[i][j] = D[i][j - 1] + 1;
			else D[i][j] = D[i][j - 1];
		}
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int X[26] = { 0 }, Y[26] = { 0 };
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		for (int i = 0; i < 26; i++)
		{
			X[i] = D[i][b] - D[i][a - 1];
			Y[i] = D[i][d] - D[i][c - 1];
		}

		bool ans = true;
		for (int j = 0; j < 26; j++)
			if (X[j] > Y[j])
			{
				ans = false;
				break;
			}

		if (ans) printf("DA\n");
		else printf("NE\n");
	}
}