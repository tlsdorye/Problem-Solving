#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

deque<char> que;
stack<int> stk;

int main()
{
	string s, u;
	bool flag = false;
	int idx = 0;

	cin >> s >> u;
	for (int i = 0; i < s.size(); i++)
	{
		que.push_back(s[i]);
		if (s[i] == u[idx]) idx++;
		else if (s[i] == u[0])
		{
			stk.push(idx);
			idx = 1;
		}
		else
		{
			while (!stk.empty()) stk.pop();
			idx = 0;
		}
		if (idx == u.size())
		{
			while (idx--) que.pop_back();
			if (!stk.empty())
			{
				idx = stk.top();
				stk.pop();
			}
			else idx = 0;
		}
	}
	if (que.empty()) cout << "FRULA";
	while (!que.empty())
	{
		cout << que.front();
		que.pop_front();
	}
}