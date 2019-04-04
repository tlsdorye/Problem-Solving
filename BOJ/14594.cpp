#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int n, m, ans = 0;
int a, b;
int wall[101];

int main() {
	cin >> n >> m;
	for (int i = 1; i < n; i++) wall[i] = 1;
	while (m--) {
		cin >> a >> b;
		for (int i = a; i < b; i++) wall[i] = 0;
	}
	for (int i = 1; i < n; i++)
		if (wall[i] == 1) ans++;
	cout << ans+1;
}
