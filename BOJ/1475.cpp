#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

vector<int> d(10, 0);

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		d[s[i] - '0']++;
	d[6] = (d[6] + d[9] + 1) / 2;
	int mmax = 0;
	for (int i = 0; i < 9; i++)
		if (mmax < d[i]) mmax = d[i];
	cout << mmax;
}