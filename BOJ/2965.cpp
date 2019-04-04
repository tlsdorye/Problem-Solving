#include <stdio.h>

int a, b, c;

int abs(int x, int y)
{
	return x < y ? y - x : x - y;
}

int jump(int a,int b,int c)
{
	int ret;
	if (abs(a, b) != 1 || abs(b, c) != 1)
	{
		if (abs(a, b) < abs(b, c))
		{
			ret = jump(b, c - 1, c);
			ret++;
			return ret;
		}
		else
		{
			ret = jump(a, a + 1, b);
			ret++;
			return ret;
		}
	}
	ret = 0;
	return ret;
}


int main()
{
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", jump(a, b, c));
	return 0;
}