#include <iostream>
#include <string>
using namespace std;


int D[101][5], S[3];

int N, ans = 0;

bool solve(int a[3], int b[5])
{
	int st = 0, ba = 0;
	for (int i = 0; i < 3; i++)
		if (a[i] == b[i]) st++;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (i != j && a[i] == b[j]) ba++;
	return b[3] == st && b[4] == ba;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 5; j++) scanf("%1d", &D[i][j]);
	for (S[0] = 1; S[0] < 10; S[0]++)
		for (S[1] = 1; S[1] < 10; S[1]++)
			for (S[2] = 1; S[2] < 10; S[2]++)
				if (S[0] != S[1] && S[1] != S[2] && S[0] != S[2])
				{
					bool flag = true;
					for (int i = 1; i <= N; i++)
						if (!solve(S, D[i])) flag = false;
					if (flag) ans++;
				}
	cout << ans;

}