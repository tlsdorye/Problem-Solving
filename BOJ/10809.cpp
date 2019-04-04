#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int d[26];
	memset(d, -1, sizeof(d));
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (d[s[i] - 'a'] == -1) d[s[i] - 'a'] = i;
	for (int i = 0; i < 26; i++)
		cout << d[i] << " ";
}