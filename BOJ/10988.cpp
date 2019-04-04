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


int main()
{
	string s, t = "";
	char c;
	cin >> s;
	deque<char> d;
	for (int i = 0; i < s.size(); i++)
		d.push_front(s[i]);
	while (!d.empty())
	{
		c = d.front();
		t += c;
		d.pop_front();
	}
	if (s == t) cout << 1;
	else cout << 0;
}