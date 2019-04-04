#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	set<string> u;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		u.insert(s);
	}
	vector<string> v;
	set<string>::iterator it = u.end();
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (it != u.find(s)) v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
}