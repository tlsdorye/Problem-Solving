#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <utility>
#include <string>
typedef long long ll;
using namespace std;

int main() {
	pair<int, int> p[3];
	pair<int, int> v[2];
	for (int i = 0; i < 3; i++)
		cin >> p[i].first >> p[i].second;
	v[0].first = p[0].second - p[1].second;
	v[0].second = p[1].first - p[0].first;
	v[1].first = p[2].first - p[0].first;
	v[1].second = p[2].second - p[0].second;
	int r = v[0].first*v[1].first + v[0].second*v[1].second;
	if (r > 0) cout << 1;
	else if (r == 0) cout << 0;
	else cout << -1;
}