#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p.begin(), p.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += p[i] * (n - i);
	cout << ans;
}