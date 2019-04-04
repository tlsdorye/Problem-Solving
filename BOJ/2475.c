#include <stdio.h>
int main() 
{
	int a[5];
	int i, k,sum=0;
	for (i = 0; i < 5; i++) scanf("%d", a + i);
	for (i = 0; i < 5; i++) sum = sum + a[i] * a[i];
	printf("%d", sum % 10);
	return 0;
}