#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	sort(A.begin(), A.end());
	deque<int> d;
	int j = 0, k = n - 1;
	for (int i = 0; i < n / 2; i++) {
		if (i % 2 == 0) {
			d.push_front(A[j++]);
			d.push_back(A[k--]);
		}
		else {
			d.push_front(A[k--]);
			d.push_back(A[j++]);
		}
	}
	if (n % 2 == 1) {
		if (abs(A[n / 2] - d.front()) > abs(A[n / 2] - d.back()))
			d.push_front(A[n / 2]);
		else d.push_back(A[n / 2]);
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
		ans += abs(d[i] - d[i + 1]);
	cout << ans;
}