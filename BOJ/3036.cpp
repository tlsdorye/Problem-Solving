#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <utility>
typedef long long ll;
using namespace std;

void solve(int x,int y) {
	int a = x, b = y, G = 0;
	if (a > b) swap(a, b);
	for (int i = 1; i <= b; i++) {
		if (a%i == 0 && b%i == 0 && G < i) G = i;
	}
	cout << x / G << "/" << y / G << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++) cin >> d[i];
	for (int i = 1; i < n; i++) solve(d[0], d[i]);
}