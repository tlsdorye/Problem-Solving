#include <stdio.h>
#include <stdlib.h>
int main()
{
	int t;
	int i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int a[100] = {0};
		for(j=0;j<n;j++) scanf("%d",a+j);
		int sum =0;
		for(j=0;j<n;j++)
		{
			sum = sum + a[j];
		}
		printf("%d\n",sum);
	}
	return 0;
}