#include <stdio.h>
#include <string.h>
#define MAX_SIZE 20020


int d[MAX_SIZE];
int sizee = 0;
int f = MAX_SIZE / 2, b = MAX_SIZE / 2;



char* string[8] = { "push_front","push_back", "pop_front" ,"pop_back" ,"size" ,"empty","front" ,"back" };

int empty()
{
	if (sizee == 0) return 1;
	else return 0;
}

void push_front(int x)
{
	d[--f] = x, sizee++;
}

void push_back(int x)
{
	d[b++] = x, sizee++;
}

int pop_front()
{
	if (!empty())
	{
		sizee--;
		return d[f++];
	}
	else return -1;
}

int pop_back()
{
	if (!empty())
	{
		sizee--;
		return d[--b];
	}
	else return -1;
}

int front()
{
	if (empty()) return -1;
	return d[f];
}

int back()
{
	if (empty()) return -1;
	return d[b - 1];
}
int size()
{
	return sizee;
}




int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		char s[20];
		scanf("%s", s);
		for (int i = 0; i < 8; i++)
		{
			if (!strcmp(s, string[i]))
			{
				int x;
				switch (i)
				{
				case 0:scanf("%d",&x), push_front(x);
					break;
				case 1:scanf("%d", &x), push_back(x);
					break;
				case 2:printf("%d\n",pop_front());
					break;
				case 3:printf("%d\n", pop_back());
					break;
				case 4:printf("%d\n", size());
					break;
				case 5:printf("%d\n", empty());
					break;
				case 6:printf("%d\n", front());
					break;
				case 7:printf("%d\n",back());
					break;
				default:
					break;
				}
				break;
			}
		}
	}
	return 0;
}