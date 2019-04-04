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
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if ('A' <= s[i] && s[i] <= 'C') ans += 3;
		else if ('D' <= s[i] && s[i] <= 'F') ans += 4;
		else if ('G' <= s[i] && s[i] <= 'I') ans += 5;
		else if ('J' <= s[i] && s[i] <= 'L') ans += 6;
		else if ('M' <= s[i] && s[i] <= 'O') ans += 7;
		else if ('P' <= s[i] && s[i] <= 'S') ans += 8;
		else if ('T' <= s[i] && s[i] <= 'V') ans += 9;
		else if ('W' <= s[i] && s[i] <= 'Z') ans += 10;
	}
	cout << ans;
}