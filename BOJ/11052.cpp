#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#define INF 987654321
typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> d(n+1);
	vector<int> cost(n+1);
	for (int i = 1; i <= n; i++) cin >> cost[i], d[i] = cost[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			d[i] = max(d[i], d[i - j] + cost[j]);
	cout << d[n];
}