#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int ans = 0, st = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'O') st += 1, ans += st;
			else st = 0;
		}
		cout << ans << "\n";
	}
}