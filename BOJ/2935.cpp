#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> P;


int main()
{
	string a, b;
	char c;
	cin >> a >> c >> b;
	if (c == '*')
	{
		cout << "1";
		for (int i = 0; i < a.size() + b.size() - 2; i++) cout << "0";
	}
	else
	{
		if (a.size() > b.size())
		{
			a[a.size() - b.size()] = '1';
			cout << a;
		}
		else if (a.size() < b.size())
		{
			b[b.size() - a.size()] = '1';
			cout << b;
		}
		else
		{
			a[0] = '2';
			cout << a;
		}
	}
}