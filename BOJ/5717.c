#include <stdio.h>	
int main()
{
	int n,m;
	int i, k;
	for (i = 0; i < 1; i=i)
	{
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)i = 1;
		else printf("%d\n", n + m);
	}
	return 0;
}