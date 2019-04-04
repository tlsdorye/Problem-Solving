#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	int t, a, b, c, d, e;
	double p[5] = { 350.34 ,230.90 ,190.55 ,125.30 ,180.90 };
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c >> d >> e;
		printf("$%.2lf\n", a*p[0] + b*p[1] + c*p[2] + d*p[3] + e*p[4]);
	}
}
