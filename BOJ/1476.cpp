#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void X(int &x) {
	x++;
	if (x > 15) x -= 15;
}

void Y(int &y) {
	y++;
	if (y > 28) y -= 28;
}

void Z(int &z) {
	z++;
	if (z > 19) z -= 19;
}

int main() {
	int a, b, c;
	int x = 0, y = 0, z = 0;
	cin >> a >> b >> c;
	for (int i = 1; i <= 7980; i++) {
		X(x), Y(y), Z(z);
		if (x == a && y == b && z == c) {
			cout << i;
			break;
		}
	}
}