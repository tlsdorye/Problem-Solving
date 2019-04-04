#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX = 1234567890;
const ll LONGMAX = 1ll * MAX * MAX;


int main()
{
	int n, p[50100], v[50100];
	double t;
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) cin >> v[i];

	double ans = -1;
	double l = 0, r = 1234567890;
	for (int i = 0; i<100; i++)
	{
		double m = (l + r) / 2;
		double a = -LONGMAX, b = LONGMAX;
		for (int i = 0; i < n; i++)
		{
			a = max(a, p[i] - v[i] * m);
			b = min(b, p[i] + v[i] * m);
		}
		if (a <= b) ans = m, r = m;
		else l = m;
	}
	if (ans <= t + 1e-8) cout << "1" << endl;
	else cout << "0" << endl;
}