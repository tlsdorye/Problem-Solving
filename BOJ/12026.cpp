#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int n;
string s;
vector<int> d(1001, INF);
vector<int> B, O, J;

int solve(int k)
{
	if (d[k] != INF) return d[k];
	vector<int> t;
	if (s[k] == 'B')  t.assign(J.begin(), J.end());
	else if (s[k] == 'O') t.assign(B.begin(), B.end());
	else t.assign(O.begin(), O.end());
	for (int i = t.size() - 1; i >= 0; i--)
		if (t[i] < k) d[k] = min(d[k], solve(t[i]) + (k - t[i])*(k - t[i]));
	return d[k];
}


int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'B') B.push_back(i);
		else if (s[i] == 'O') O.push_back(i);
		else J.push_back(i);
	}
	d[0] = 0;
	int ans = solve(n - 1);
	if (ans == INF) cout << "-1";
	else cout << ans;
}