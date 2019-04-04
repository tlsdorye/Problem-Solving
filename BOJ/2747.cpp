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
vector<int> d;

int main()
{
	int n;
	cin >> n;
	d.resize(n+1);
	d[0] = 0, d[1] = 1;
	for (int i = 2; i <= n; i++)
		d[i] = d[i - 1] + d[i - 2];
	cout << d[n];
}