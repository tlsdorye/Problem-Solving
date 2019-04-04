#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <utility>
#include <string>
#define MAX 200001
typedef long long ll;
using namespace std;

int main() {
	int n, m;
	vector<int> d(MAX);
	cin >> n >> m;
	if (n == m) {
		cout << 0;
		return 0;
	}
	if (n > m) {
		cout << n - m;
		return 0;
	}
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int x = q.front(), y;
		q.pop();
		y = x + 1;
		if (y < MAX && d[y] == 0) q.push(y), d[y] = d[x] + 1;
		y = x - 1;
		if (y >= 0 && d[y] == 0) q.push(y), d[y] = d[x] + 1;
		y = x * 2;
		if (y < MAX && d[y] == 0) q.push(y), d[y] = d[x] + 1;
		if (d[m] != 0) break;
	}
	cout << d[m];
}