#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> c = {  "dz=", "c=","c-", "d-", "lj", "nj", "s=","z=" };

int allfind(string &s,string u)
{
	int ret = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == u[0] && s[i + 1] == u[1])
		{
			ret++;
			s[i] = '!', s[i + 1] = '!';
		}
	return ret;
}

int allfind0(string &s, string u)
{
	int ret = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == u[0] && s[i + 1] == u[1] && s[i+2] == u[2])
		{
			ret++;
			s[i] = '!', s[i + 1] = '!', s[i + 2] = '!';
		}
	return ret;
}

int main()
{
	string s;
	cin >> s;
	int alpha = 0;
	int ans = 0;
	ans += allfind0(s, c[0]);
	for (int i = 1; i < 8; i++)
		ans += allfind(s, c[i]);
	for (int i = 0; i < s.size(); i++)
		if (0 <= s[i] - 'a' && s[i] - 'a' <= 25) alpha++;
	cout << ans + alpha;
	return 0;
}