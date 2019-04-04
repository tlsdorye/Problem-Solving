#include <iostream>
typedef long long ll;
using namespace std;

ll d[92];
ll zero = 1, one = 1, tmp = 0;

void make() {
	d[1] = 1;
	d[2] = 1;
	d[3] = 2;
	for (int i = 4; i < 91; i++) {
		d[i] = zero * 2 + one;
		tmp = zero;
		zero += one;
		one = tmp;
	}
}

int main() {
	int n;
	cin >> n;
	make();
	cout << d[n];
}