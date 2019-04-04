#include <stdio.h>
#include <algorithm>

using namespace std;

int S[2][100005] = { 0 };
int H[100005];
int top = 0, ans = 0,low = 2100000000;

bool empty()
{
	if (top == 0) return true;
	return false;
}

void push(int data,int dist)
{
	top++;
	S[0][top] = data;
	S[1][top] = dist;
}

void pop()
{
	top--;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", H + i);
	
	for (int i = 1; i <= n+1; i++)
	{	
		H[n] = min(H[n], H[i]);
		if (empty() || H[i] > S[0][top]) push(H[i], i);
		else
		{
			pop(), i--;
			if (empty()) ans = max(ans, S[0][top + 1] * i);
			else ans = max(ans, S[0][top + 1] * (i - S[1][top]));
		}
	}
	printf("%d", ans);
	return 0;
}