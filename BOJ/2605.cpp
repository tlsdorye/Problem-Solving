#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <utility>
typedef long long ll;
using namespace std;

int main() {
	int n, tmp;
	list<int> l;
	list<int>::iterator itor;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		itor = l.begin();
		while (tmp--) itor++;
		l.insert(itor, i);
	}
	while (!l.empty()) {
		cout << l.back() << " ";
		l.pop_back();
	}
}