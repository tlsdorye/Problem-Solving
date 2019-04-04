#include <stdio.h>	
int main()
{
	int a[6];
	int i, k, j;
	for (i = 0; i < 6; i++) scanf("%d", a + i);
	if (1 != a[0] ) printf("%d ",1-a[0]);
	if (1 == a[0]) printf("0 ");
	if (1 != a[1] ) printf("%d ",1-a[1]);
	if (1 == a[1]) printf("0 ");
	if (2 != a[2] ) printf("%d ", 2 - a[2]);
	if (2 == a[2]) printf("0 ");
	if (2 != a[3] ) printf("%d ", 2 - a[3]);
	if (2 == a[3]) printf("0 ");
	if (2 != a[4] ) printf("%d ", 2 - a[4]);
	if (2 == a[4]) printf("0 ");
	if (8 != a[5] ) printf("%d", 8 - a[5]);
	if (8 == a[5]) printf("0");

	return 0;
}