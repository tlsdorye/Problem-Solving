#include <stdio.h>
#include <string.h>

double s[100];
char E[100];
double V[26];
int bottom = 0;
int top = 0;

void push(double data)
{
	top++, s[top] = data;
}

double pop()
{
	if (top != 0)
	{
		top--;
		return s[top + 1];
	}
	return NULL;
}

bool isalpha(int idx)
{
	if (E[idx] >= 'A' && E[idx] <= 'Z') return true;
	return false;
}
int main()
{
	int n;
	scanf("%d %s", &n, E);
	for (int i = 0; i < n; i++) scanf("%lf", &V[i]);
	for (int i = 0; i < strlen(E); i++)
	{
		if (isalpha(i)) push(V[E[i]-'A']);
		else
		{
			double b = pop();
			double a = pop();
			if (E[i] == '+') push(a + b);
			else if (E[i] == '-') push(a - b);
			else if (E[i] == '*') push(a * b);
			else push(a / b);
		}
	}
	printf("%.2lf", pop());
	return 0;
}