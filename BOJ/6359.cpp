#include <iostream>
using namespace std;

int t, n;
int room[102];

void solve(int x) {
	for (int i = x; i <= n; i = i + x) {
		if (room[i] == 0) room[i] = 1;
		else if (room[i] == 1) room[i] = 0;
	}
}

int main() {
	cin >> t;
	while (t--) {
		int ans = 0;
		for (int i = 0; i < 102; i++) room[i] = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) solve(i);
		for (int i = 1; i <= n; i++)
			if (room[i] == 1) ans++;
		cout << ans << endl;
	}
}