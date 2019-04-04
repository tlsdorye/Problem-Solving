#include <stdio.h>
#include <stdlib.h>
int main()
{
	int t;
	int i,j;
	int Y=100,K=100;
	scanf("%d",&t);
	int* a = (int*)malloc(sizeof(int)*2*t);
	for(i=0;i<2*t;i++) scanf("%d",a+i);
	for(i=0;i<2*t;i=i+2)
	{
		if(a[i]>a[i+1]) K=K-a[i];
		else if(a[i]<a[i+1]) Y=Y-a[i+1];
	}
	printf("%d\n%d",Y,K);

	
	return 0;
}