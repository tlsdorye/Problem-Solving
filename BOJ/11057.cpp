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
	int n;
	cin >> n;
	vector<vector<int>> d(n,vector<int>(10,0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 10; j++)
		{
			if (i == 0) d[i][j] = 1;
			else
			{
				if (j == 0) d[i][j] = 1;
				else d[i][j] = d[i][j - 1] + d[i - 1][j];
			}
			d[i][j] %= 10007;
		}
	int sum = 0;
	for (int i = 0; i < 10; i++) sum += d[n - 1][i], sum;
	cout << sum % 10007;
}