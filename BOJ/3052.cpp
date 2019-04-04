#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int main() {
	int tmp, m[42] = {0};
	for (int i = 0; i < 10; i++) {
		cin >> tmp;
		m[tmp % 42]++;
	}
	int ans = 0;
	for (int i = 0; i < 42; i++)
		if (m[i]) ans++;
	cout << ans;
}