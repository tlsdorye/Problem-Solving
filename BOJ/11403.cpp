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
	int t;
	cin >> t;
	vector<vector<int>> adj(t, vector<int>());
	for (int i = 0; i < t; i++) adj[i].resize(t);
	for (int i = 0; i < t; i++)
		for (int j = 0; j < t; j++) cin >> adj[i][j];

	for (int i = 0; i < t; i++)
		for (int j = 0; j < t; j++)
		{
			for (int k = 0; k < t; k++)
			{
				if (adj[k][j] || (adj[k][i] && adj[i][j])) adj[k][j] = 1;
			}
		}
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
			printf("%d ", adj[i][j]);
		cout << endl;
	}
}