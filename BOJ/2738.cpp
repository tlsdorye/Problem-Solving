#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <utility>
typedef long long ll;
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[100][100] = { 0 }, b[100][100] = { 0 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> b[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] += b[i][j];
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}