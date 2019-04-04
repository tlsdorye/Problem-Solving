#include <stdio.h>
#include <string.h>

int s[100];
char E[100];
int bottom = 0;
int top = 0;

void push(int data)
{
	top++, s[top] = data;
}

int pop()
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
	if (E[idx] >= 65 && E[idx] <= 90) return true;
	return false;
}

bool isoperate(int idx)
{
	if (E[idx] == '*' || E[idx] == '-' || E[idx] == '+' || E[idx] == '/') return true;
	return false;
}

bool priority(int x, int y)
{
	int a, b;
	if (x == '+' || x == '-') a = 0;
	else a = 1;
	if (y == '+' || y == '-') b = 0;
	else b = 1;
	if (a > b) return true;
	else return false;
}


int main()
{
	scanf("%s", E);
	for (int i = 0; i < strlen(E); i++)
	{
		if (isalpha(i)) printf("%c", E[i]);
		else if (isoperate(i))
		{
			while (1)
			{
				if (top == 0 || s[top] == '(' || priority(E[i], s[top]))
				{
					push(E[i]);
					break;
				}
				else printf("%c", pop());
			}
		}
		else if (E[i] == '(') push(E[i]);
		else
		{

			while (s[top] != '(') printf("%c", pop());
			pop();
		}
	}
	while (top>0) printf("%c", pop());
	return 0;
}