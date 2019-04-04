#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[3],i,k,m;
	for(i=0;i<3;i++) scanf("%d",a+i);
	for(k=0;k<3;k++)
	{
		for(i=0;i<2;i++)
		{
			if(a[i]>a[i+1])
			{
				m=a[i+1]; a[i+1]=a[i]; a[i]=m;
			}
		}
	}
	for(i=0;i<3;i++) printf("%d ",a[i]);
	return 0;
}