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
	int n;
	cin >> n;
	vector<int> d(n, 0),s(n,0);
	for (int i = 0; i < n; i++) cin >> d[i];
	s[0] = d[0];
	int max = s[0];
	for (int i = 1; i < n; i++)
	{
		if (s[i - 1] + d[i] > d[i]) s[i] = s[i - 1] + d[i];
		else s[i] = d[i];
		if (max < s[i])max = s[i];
	}
	cout << max;
	
}