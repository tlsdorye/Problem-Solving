#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	vector<int> d(n);
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] < A[j] && d[i] <= d[j]) d[i] = d[j] + 1;
		}
		if (d[i] == 0) d[i] = 1;
		if (max < d[i]) max = d[i];
	}
	cout << max;
}