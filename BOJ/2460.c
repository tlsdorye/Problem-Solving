#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[20];
	int b[10];
	int i,j;
	for(i=0;i<20;i++) scanf("%d",a+i);
	for(i=0;i<20;i=i+2)
	{
		b[i/2]=a[i+1]-a[i];
	}
	int sum = 0;
	int max = 0;
	for(i=0;i<10;i++)
	{
		sum = sum+b[i];
		if(max<sum) max = sum;
	}
	printf("%d",max);
	return 0;
}