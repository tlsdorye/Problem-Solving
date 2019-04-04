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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a + d < b + c) cout << a + d;
	else cout << b + c;
}
