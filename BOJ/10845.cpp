#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;



int main()
{
	queue<int> que;
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		int x;
		cin >> s;
		if (s == "push")
		{
			cin >> x;
			que.push(x);
		}
		if (s == "pop")
		{
			if (!que.empty())
			{
				cout << que.front() << "\n";
				que.pop();
			}
			else cout << "-1" << "\n";
		}
		if (s == "empty")
		{
			if (que.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		if (s == "front")
		{
			if (!que.empty()) cout << que.front() << "\n";
			else cout << "-1" << "\n";
		}
		if (s == "back")
		{
			if (!que.empty()) cout << que.back() << "\n";
			else cout << "-1" << "\n";
		}
		if (s == "size")
		{
			cout << que.size() << "\n";
		}
	}
}