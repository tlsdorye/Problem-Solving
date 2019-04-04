#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	int i,j;
	int sum = 0;
	scanf("%d",&n);
	int* a = (int*)malloc(sizeof(int)*2*n);
	for(i=0;i<2*n;i++) scanf("%d",a+i);
	for(i=0;i<2*n;i=i+2)
	{
		sum = sum + a[i+1]%a[i];
	}
	printf("%d",sum);
	return 0;
}