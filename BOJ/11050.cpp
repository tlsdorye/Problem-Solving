#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int factorial(int n) {
	if (n == 0) return 1;
	if (n == 1) return 1;
	else return factorial(n - 1)*n;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << factorial(n) / (factorial(k)*factorial(n - k));
}