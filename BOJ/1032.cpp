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
	string ans = "";
	while (n--)
	{
		string s;
		cin >> s;
		if (ans == "") ans = s;
		for (int i = 0; i < s.size(); i++)
			if (ans[i] != s[i]) ans[i] = '?';
	}
	cout << ans;
}