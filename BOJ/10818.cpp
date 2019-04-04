#include <iostream>
using namespace std;

int main() {
	int maxx = -999999999, minn = 999999999;
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (maxx < tmp) maxx = tmp;
		if (minn > tmp) minn = tmp;
	}
	cout << minn << " " << maxx;
}