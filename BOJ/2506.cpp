#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>	d(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		if (i > 0 && d[i - 1] != 0 && d[i] == 1) 
			d[i] += d[i - 1];
		ans += d[i];
	}
	cout << ans;
}