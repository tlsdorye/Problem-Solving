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
vector<int> d;

int solve(int a,int b) {
	if (a%b == 0) return b;
	else return solve(b, a%b);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		int g = solve(x, y);
		cout << g*(x/g)*(y/g) << endl;
	}
}