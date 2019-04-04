#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	int i,j;
	int q[5] = {0};
	scanf("%d",&n);
	int* a = (int*)malloc(sizeof(int)*2*n);
	for(i=0;i<2*n;i++) scanf("%d",a+i);
	for(i=0;i<2*n;i=i+2)
	{
		if(a[i]>0)
		{
			if(a[i+1]>0) q[1]++;
			if(a[i+1]==0) q[0]++;
			if(a[i+1]<0) q[4]++;
		}
		else if(a[i]<0)
		{
			if(a[i+1]>0) q[2]++;
			if(a[i+1]==0) q[0]++;
			if(a[i+1]<0) q[3]++;
		}		
		else q[0]++;
	}
	
	for(i=1;i<5;i++) printf("Q%d: %d\n",i,q[i]);
	printf("AXIS: %d",q[0]);
	
	return 0;
}