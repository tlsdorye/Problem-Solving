#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#include <map>
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	ll d[31][31] = { 0 };
	for (int i = 0; i <= 30; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) d[i][j] = 1;
			else d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
		}
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		cout << d[m][n] << endl;
	}
}