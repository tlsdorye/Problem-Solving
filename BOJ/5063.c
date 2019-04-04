#include <stdio.h>	
int main()
{
	int n;
	int i, k;
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int)*3*n);
	for (i = 0; i < 3*n; i++) scanf("%d", a + i);

	for (i = 0; i < 3*n; i=i+3)
	{
		if (a[i+1] - a[i+2]> a[i]) printf("advertise");
		else if (a[i + 1] - a[i + 2] == a[i]) printf("does not matter");
		else printf("do not advertise");
		if (i != 3 * (n - 1)) printf("\n");
	}
	return 0;
}