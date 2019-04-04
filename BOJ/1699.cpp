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
	vector<int> d(n+1, INF);
	d[0] = 0;
	for (int i = 1; i <= sqrt(n) + 1; i++)
		for (int j = i*i; j <= n; j++)
			d[j] = min(d[j], d[j - i*i] + 1);
	cout << d[n];
}