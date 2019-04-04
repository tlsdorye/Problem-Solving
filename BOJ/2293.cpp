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
	vector<int> coin(n+1, 0), d(k+1,0);
	for (int i = 1; i <= n; i++) cin >> coin[i];
	for (int i = 1; i <= n; i++)
	{
		if (coin[i] > k) continue;
		d[coin[i]]++;
		for (int j = coin[i]; j <= k; j++)
			d[j] = d[j] + d[j - coin[i]];
	}
	cout << d[k];
}