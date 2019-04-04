#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#include <map>
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	ll d[101] = { 0,1,1,1,2,2,0 };
	for (int i = 6; i <= 100; i++) d[i] = d[i - 1] + d[i - 5];
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << d[n] << endl;
	}
}