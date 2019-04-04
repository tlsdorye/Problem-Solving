#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;


int main()
{
	char d[100][100] = { 0 };
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) cin >> d[i][j];
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < r; i++)
		for (int j = c, k = c - 1; j < c * 2; j++, k--)
			d[i][j] = d[i][k];
	for (int i = r, k = r - 1; i < r * 2; i++, k--)
		for (int j = 0; j < c * 2; j++)
		{
			d[i][j] = d[k][j];
		}

	if (d[a - 1][b - 1] == '#') d[a - 1][b - 1] = '.';
	else d[a - 1][b - 1] = '#';

	for (int i = 0; i < r * 2; i++)
	{
		for (int j = 0; j < c * 2; j++)
			cout << d[i][j];
		cout << endl;
	}

}