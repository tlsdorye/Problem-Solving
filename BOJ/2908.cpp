#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int reverse(int n) {
	int r[3];
	int x = 10;
	for (int i = 0; i < 3; i++) {
		r[i] = n%x;
		n /= x;
	}
	int t = 0;
	x = 1;
	for (int i = 0; i < 3; i++) {
		t += r[2 - i] * x;
		x *= 10;
	}
	return t;
}

int main() {
	int a, b;
	cin >> a >> b;
	a = reverse(a);
	b = reverse(b);
	if (a > b) cout << a;
	else cout << b;
}