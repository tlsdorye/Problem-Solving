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
	vector<int> d(n+1, 0);
	d[0] = 1;
	for (int i = 2; i <= n; i += 2)
	{
		d[i] = d[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) d[i] += d[i - j] * 2;
	}
	cout << d[n];
}