#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;



int main() {
	int n;
	int a=0, b=0, c=0;
	int ma = 0, mb = 0, mc = 0;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (ma < a) {
			ans = i+1;
			ma = a, mb = b, mc = c;
		}
		else if (ma == a) {
			if (mb > b) {
				ans = i+1;
				ma = a, mb = b, mc = c;
			}
			else if (mb == b) {
				if (mc > c) {
					ans = i+1;
					ma = a, mb = b, mc = c;
				}
			}
		}
	}
	cout << ans;
}
