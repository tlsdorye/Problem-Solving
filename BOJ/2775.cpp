#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <string>
#include <cmath>
#include <functional>
#define MAX 987654321
typedef long long ll;
using namespace std;

int d[15][15] = { 0 };

void solve() 
{
	for (int i = 1; i <= 14; i++)
		for (int j = 1; j <= 14; j++)
			d[i][j] = d[i][j - 1] + d[i - 1][j];
}


int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < 15; i++) d[0][i] = i;
	solve();
	int a, b;
	while (t--)
	{
		cin >> a >> b;
		cout << d[a][b] << endl;
	}
}