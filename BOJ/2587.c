#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[5] = {0};
	int m,i,k;
	for(i=0;i<5;i++) scanf("%d",a+i);
	
	for(i=0;i<5;i++)
	{
		for(k=0;k<4;k++)
		{
			if(a[k]>a[k+1])
			{
				m=a[k+1]; a[k+1]=a[k]; a[k]=m;
			}
		}
	}
	printf("%d\n",(a[0]+a[1]+a[2]+a[3]+a[4])/5);
    printf("%d",a[2]);
	return 0;
}