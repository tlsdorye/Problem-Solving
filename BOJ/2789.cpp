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
	string s = "CAMBRIDGE", t;
	cin >> t;
	for (int i = 0; i < t.size(); i++)
		for (int j = 0; j < s.size(); j++)
			if (t[i] == s[j]) t[i] = '!';

	for (int i = 0; i < t.size(); i++)
		if (t[i] != '!') cout << t[i];
}