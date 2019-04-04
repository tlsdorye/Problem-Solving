#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int num = 0;
	bool flag = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (!flag && s[i] != ' ') flag = true, num++;
		if (s[i] == ' ') flag = false;
	}
	cout << num;
	return 0;
}