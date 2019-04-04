#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int n;
vector<vector<char>> d;

void erase(int x)
{
	for (int i = x; i < n; i += x * 3)
		for (int j = x; j < n; j += x * 3)
		{
			for (int a = i; a < i + x; a++)
				for (int b = j; b < j + x; b++)
					d[a][b] = ' ';
		}

}

void solve(int x)
{
	if (x == n) return;
	else
	{
		erase(x);
		solve(x * 3);
	}
	return;
}

int main()
{
	cin >> n;
	d.resize(n, vector<char>());
	for (int i = 0; i < n; i++) d[i].resize(n, '*');
	solve(1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << d[i][j];
		cout << "\n";
	}
		
}