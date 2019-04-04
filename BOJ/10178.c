#include <stdio.h>	
int main()
{
	int t;
	int i, k;
	scanf("%d", &t);
	int* a = (int*)malloc(sizeof(int)*2*t);
	for (i = 0; i <2*t; i++) scanf("%d", a + i);

	for (i = 0; i < 2*t; i = i + 2) {
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", a[i]/a[i+1],a[i]%a[i+1]);
	}
	return 0;
}