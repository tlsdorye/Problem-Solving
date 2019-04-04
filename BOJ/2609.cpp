#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (b < a) swap(a, b);
	int G = 0, L = 0;
	for (int i = 1; i <= b; i++)
		if (a%i == 0 && b%i == 0 && G < i) G = i;
	L = (a/G)*(b/G)*G;
	cout << G << endl << L;
}