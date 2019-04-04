#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,m,i,k;
	scanf("%d",&n);
	int* a = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++) scanf("%d",a+i);
	
	for(i=0;i<n;i++)
	{
		for(k=0;k<n-1;k++)
		{
			if(a[k]>a[k+1])
			{
				m=a[k+1]; a[k+1]=a[k]; a[k]=m;
			}
		}
	}
	for(i=0;i<n;i++) printf("%d\n",a[i]);
	return 0;
}