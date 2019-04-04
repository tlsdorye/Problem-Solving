#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int A[10];
		for (int i = 0; i < 10; i++) cin >> A[i];
		sort(A, A + 10);
		cout << A[7] << endl;
	}
}