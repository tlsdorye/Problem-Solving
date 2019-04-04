#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[8];
	int b[4];
	int i,j;
	for(i=0;i<8;i++) scanf("%d",a+i);
	for(i=0;i<8;i=i+2)
	{
		b[i/2]=a[i+1]-a[i];
	}
	int sum = 0;
	int max = 0;
	for(i=0;i<4;i++)
	{
		sum = sum+b[i];
		if(max<sum) max = sum;
	}
	printf("%d",max);
	return 0;
}