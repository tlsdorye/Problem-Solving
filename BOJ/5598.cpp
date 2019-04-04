#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] - 'A') < 3) s[i] += 23;
		else s[i] -= 3;
	}
	cout << s;
}
