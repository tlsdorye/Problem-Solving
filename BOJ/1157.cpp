#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int d[26] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		if ('a' <= s[i] && s[i] <= 'z') d[s[i] - 'a']++;
		else d[s[i] - 'A']++;
	}
	int maxx = 0, index = 0;
	for (int i = 0; i < 26; i++)
		if (maxx < d[i]) maxx = d[i], index = i;
	for (int i = 0; i < 26; i++)
	{
		if (d[i] == maxx && index != i)
		{
			cout << '?';
			return 0;
		}
	}
	cout << (char)(index + 'A');
	return 0;
}