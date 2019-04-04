#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,k;
	scanf("%d",&n);
	int* a = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++) scanf("%d",a+i);
	int sum =0;
	for(i=0;i<n;i++)
	{
		sum = sum +a[i];
	}
	printf("%d",sum-n+1);
	return 0;
}