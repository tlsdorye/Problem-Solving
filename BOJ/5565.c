#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[10];
	int i,j;
	for(i=0;i<10;i++) scanf("%d",a+i);
	int sum = a[0];
	for(i=1;i<10;i++)
	{
		sum=sum-a[i];
	}
	printf("%d",sum);
	return 0;
}