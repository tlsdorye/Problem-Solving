#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int ans = 0;
	int stack = 0, num = 0;
	int expo = 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			int temp = s[i] - '0';
			num += temp * expo;
			expo *= 10;
		}
		else if(s[i] == '+')
		{
			stack += num;
			num = 0;
			expo = 1;
		}
		else if (s[i] == '-')
		{
			stack += num;
			num = 0;
			expo = 1;
			ans -= stack;
			stack = 0;
		}
	}
	stack += num;
	ans += stack;
	cout << ans;
}