#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <utility>
typedef long long ll;
using namespace std;

int main() {
	int n;
	int d[5] = { 0 };
	cin >> n;
	while (n--) {
		for (int i = 0; i < 5; i++) cin >> d[i];
		sort(d, d + 5);
		if ((d[3] - d[1]) >= 4) cout << "KIN" << endl;
		else cout << d[1] + d[2] + d[3] << endl;
	}
}