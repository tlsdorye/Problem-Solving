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
	int t;
	cin >> t;
	while (t--)
	{
		int n, c=0, tmp;
		double sum = 0, g = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp >> g;
			c += tmp;
			sum += tmp*g;
		}
		printf("%d %.1lf\n", c, sum / c);
	}
}