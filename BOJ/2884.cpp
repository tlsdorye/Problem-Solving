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
	int a, b;
	cin >> a >> b;
	int t = 24 * 60 + a * 60 + b - 45;
	if (t >= 1440) t -= 1440, cout << t / 60 << " " << t % 60;
	else cout << t / 60 << " " << t % 60;
}
