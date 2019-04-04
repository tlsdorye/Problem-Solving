#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int gcd(int a, int b)
{
	if (a%b == 0) return b;
	else gcd(b, a%b);
}

int main()
{
	int n, g;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++) cin >> d[i];
	g = d[0];
	for (int i = 1; i <= n - 1; i++) g = gcd(g, d[i]);
	for (int i = 1; i <= g; i++)
		if (g%i == 0) cout << i << endl;

}