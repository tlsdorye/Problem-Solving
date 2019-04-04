#include <stdio.h>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

stack<char> s;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char c[51];
		scanf("%s", c);
		int l = strlen(c);
		for (int i = 0; i < l; i++)
		{
			if (c[i] == ')')
				if (!s.empty() && s.top() == '(') s.pop();
				else
				{
					printf("NO\n");
					break;
				}
			else s.push(c[i]);
			if (i == l - 1)
			{
				if (s.empty()) printf("YES\n");
				else printf("NO\n");
			}
		}
		while (!s.empty()) s.pop();
	}
	return 0;
}