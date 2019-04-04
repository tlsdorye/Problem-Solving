#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#include <map>
#include <functional>
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> d(n, 0);
	for (int i = 0; i < n; i++) cin >> d[i];
	sort(d.begin(), d.end());
	for (int i = 0; i < n; i++) printf("%d\n", d[i]);
}