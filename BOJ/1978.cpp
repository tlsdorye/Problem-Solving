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
	int d[1001] = { 1,1,0 };
	for (int i = 2; i <= 1000; i++)
	{
		for (int j = i*2; j <= 1000; j += i)
			d[j] = 1;
	}
	int n;
	cin >> n;
	int ans = 0;
	while (n--)
	{
		int x;
		cin >> x;
		if (d[x] == 0) ans++;
	}
	cout << ans;
}