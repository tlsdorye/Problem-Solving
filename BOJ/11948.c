#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[4];
	int b[2];
	int i,j;
	for(i=0;i<4;i++) scanf("%d",a+i);
	for(i=0;i<2;i++) scanf("%d",b+i);
	int min1 =100;
	for(i=0;i<4;i++)
	{
		if(min1>a[i]) min1 = a[i]; 
	}
    int min2 =100;
	for(i=0;i<2;i++)
	{
		if(min2>b[i]) min2 = b[i]; 
	}
	printf("%d",a[0]+a[1]+a[2]+a[3]+b[0]+b[1]-min1-min2);
	return 0;
}