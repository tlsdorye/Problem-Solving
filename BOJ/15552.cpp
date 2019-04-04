#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	int a, b;
	while (T--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}