#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s[1002];

int main()
{
	cin >> s[0];
	int l = s[0].length();
	for (int i = 1; i < l; i++) s[i] = s[i-1].substr(1, l - 1);
	sort(s,s+l);
	for (int i = 0; i < l; i++) cout << s[i] << endl;
	return 0;
}