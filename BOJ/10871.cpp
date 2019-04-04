#include <stdio.h>

int main()
{
	int n, m,c;
	scanf("%d %d", &n, &m);
	while (n--)
	{
		scanf("%d", &c);
		if (c < m) printf("%d ", c);
	}
	return 0;
}