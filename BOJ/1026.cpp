#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <string>
#include <cmath>
#define MAX 987654321
typedef long long ll;
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[50] = { 0 }, b[50] = { 0 };
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i] * b[n - i - 1];
	cout << ans;
}