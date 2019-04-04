#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

stack<char> ns;
int ans;
char s[100010];
int cut[100010] = { 0 };

int main() {

	scanf("%s", s);
	int l = strlen(s);

	for (int i = 0; i < l; i++)
		if (s[i] == '(' && s[i + 1] == ')') s[i] = '*', s[i + 1] = '*', i++;

	for (int i = 0,j=0; i < l; i++)
	{
		if (s[i] == '(')
		{
			ns.push(s[i]);
			j++;
		}
		else if (s[i] == '*')
		{
			cut[j]++;
		}
		else if (s[i] == ')')
		{
			ans += cut[j] / 2 + 1;
			if (ns.top() == '(') cut[j-1] += cut[j];
			cut[j--] = 0;
		}
	}

	cout << ans;

	return 0;
}