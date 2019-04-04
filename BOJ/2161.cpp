#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int main() {
	int n;
	cin >> n;
	deque<int> d;
	for (int i = 0; i < n; i++) d.push_back(i + 1);
	while (d.size() > 1) {
		cout << d[0] << " ";
		d.pop_front();
		d.push_back(d[0]);
		d.pop_front();
	}
	cout << d[0];
}