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

int main()
{
	string s[2][8] = { "000","001","010","011","100","101","110","111",
						"0","1","10","11","100","101","110","111" };
	string t;
	cin >> t;
	for (int i = 0; i < t.size(); i++)
	{
		if (i == 0) cout << s[1][t[i] - '0'];
		else cout << s[0][t[i] - '0'];
	}
}