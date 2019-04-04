#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,k;
	scanf("%d",&n);
	int* a = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++) scanf("%d",a+i);
	int v;
	int check = 0;
	scanf("%d",&v);
	for(i=0;i<n;i++)
	{
		if(v==a[i]) check++;
	}
	printf("%d",check);
	return 0;
}