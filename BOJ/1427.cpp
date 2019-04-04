#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <string>
#include <cmath>
#include <functional>
#define MAX 987654321
typedef long long ll;
using namespace std;

vector<int> d;

void solve(ll n)
{
	if (n == 0) return;
	d.push_back(n % 10);
	solve(n / 10);
}

int main()
{
	ll n;
	cin >> n;
	solve(n);
	sort(d.begin(), d.end(),greater<int>());
	for (int i = 0; i < d.size(); i++) cout << d[i];
}