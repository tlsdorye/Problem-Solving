#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <string>
#define MAX 200001
typedef long long ll;
using namespace std;

int d[4] = { 0,1,0,0 };

void myswap(char c)
{
	if (c == 'A') swap(d[1], d[2]);
	if (c == 'B') swap(d[2], d[3]);
	if (c == 'C') swap(d[1], d[3]);
}

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		myswap(s[i]);
	for (int i = 1; i <= 3; i++)
		if (d[i] == 1) cout << i;
}