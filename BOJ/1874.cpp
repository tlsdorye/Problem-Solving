#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int _max;
queue<char> que;
stack<int> st;

int main()
{
	int N, x;
	bool flag = false;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &x);
		if (!st.empty() && st.top() == x)
		{
			st.pop();
			que.push('-');
		}
		else if (_max < x)
		{
			for (int i = _max + 1; i < x; i++)
				st.push(i), que.push('+');
			_max = x;
			que.push('+');
			que.push('-');
		}
		else flag = true;
	}
	if (flag)
	{
		printf("NO");
		return 0;
	}
	while (!que.empty())
	{
		printf("%c\n", que.front());
		que.pop();
	}
}