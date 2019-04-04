#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <string>
#define MAX 200001
typedef long long ll;
using namespace std;

int main()
{
	int box[100][100] = { 0 };
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) cin >> box[i][j];
		int move = 0;
		for (int i = 0; i < m; i++)
		{
			int empty = 0;
			for (int j = n - 1; j >= 0; j--)
			{
				if (box[j][i] == 0) empty++;
				if (box[j][i] == 1) move += empty;
			}
		}
		cout << move << endl;
	}
}