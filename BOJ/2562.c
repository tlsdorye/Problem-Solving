#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[9] = {0};
	int b[9] = {0};
	int i,k,j,m;
	int ch1 =0;
	for(i=0;i<9;i++) scanf("%d",a+i);
	for(i=0;i<9;i++) b[i]=a[i];
	for(i=0;i<9;i++)
	{
		for(k=0;k<8;k++)
		{
			if(b[k]>b[k+1]) { m=b[k+1]; b[k+1]=b[k]; b[k]=m; }
		}
	}
	for(i=0;i<9;i++)
	{
		if(b[8]==a[i]) ch1=i;
	}
	printf("%d\n",b[8]);
	printf("%d",ch1+1);
	return 0;
}