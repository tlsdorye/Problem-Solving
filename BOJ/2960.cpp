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
	int n, k;
	cin >> n >> k;
	vector<int> d(n + 1, 0);
	queue<int> que;
	que.push(2);
	while (!que.empty())
	{
		int t = que.front();
		que.pop();
		if (d[t] != 0) continue;
		for (int i = 1; t*i <= n; i++)
		{
			if (d[t*i] == 0)
			{
				d[t*i] = 1;
				k--;
			}
			if (k == 0)
			{
				cout << t*i;
				return 0;
			}
		}
		for (int i = 2; i < d.size(); i++) if (d[i] == 0) que.push(i);
	}
}