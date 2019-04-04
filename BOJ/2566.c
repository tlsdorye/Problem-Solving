#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[81] = {0};
	int b[81] = {0};
	int c,d;
	int m,i,j,k;
	int ch1 =0;
	for(i=0;i<81;i++) scanf("%d",a+i);
	for(i=0;i<81;i++) b[i] = a[i];
	for(i=0;i<81;i++)
	{
		for(k=0;k<80;k++)
		{
			if(b[k]>b[k+1])
			{
				m=b[k+1];
				b[k+1]=b[k];
				b[k]=m;
			}
		}
	}
	for(i=0;i<81;i++)
	{
		if(b[80]==a[i]) ch1 = i;
	}
	c = ch1/9;
	d = ch1%9;
	printf("%d\n%d %d",b[80],c+1,d+1);
	return 0;
}