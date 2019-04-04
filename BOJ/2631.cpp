#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define INF 987654321
typedef long long ll;
using namespace std;

vector<int> lis;
int n, t, ans = 0;


int main() {
	cin >> n;
	lis.push_back(-INF);

	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (lis.back() < t) {
			lis.push_back(t);
			ans++;
		}
		else {
			auto itor = lower_bound(lis.begin(), lis.end(), t);
			*itor = t;
		}
	}
	cout << n-ans;

	return 0;
}