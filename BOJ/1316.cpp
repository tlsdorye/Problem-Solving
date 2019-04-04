#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	int ans = n;
	while (n--)
	{
		string s;
		vector<bool> d(26, false);
		cin >> s;
		d[s[0] - 'a'] = true;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i - 1] != s[i] && d[s[i] - 'a'])
			{
				ans--;
				break;
			}
			else d[s[i] - 'a'] = true;
		}
	}
	cout << ans;
}