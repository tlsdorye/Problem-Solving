#include <stdio.h>	
int main()
{
	int a[3], b[3];
	int i, k;
	int n, m;
	for (i = 0; i < 3; i++)scanf("%d %d", a+i,b+i);

	if (a[0] != a[1])
	{
		if (a[0] != a[2]) n = a[0];
		else n = a[1];
	}
	else n = a[2];

	if (b[0] != b[1])
	{
		if (b[0] != b[2]) m = b[0];
		else m = b[1];
	}
	else m = b[2];
	printf("%d %d",n,m);

	return 0;
}