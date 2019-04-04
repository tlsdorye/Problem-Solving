#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

char str[11];
int len, ans;
bool check()
{
	if (len == 1) return true;
	for (int i = 1; i < len; i++)
		if (str[i - 1] == str[i]) return false;
	return true;
}

int main()
{
	scanf("%s", str);
	len = strlen(str);
	sort(str, str + len);
	do
	{
		if (check()) ans++;
	} while (next_permutation(str,str+len));
	printf("%d", ans);
}