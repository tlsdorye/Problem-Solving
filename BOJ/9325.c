#include <stdio.h>
#include <stdlib.h>
int main()
{
	int t;
	int i,j;
	scanf("%d",&t);
	int* a = (int*)malloc(sizeof(int)*t);

	
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d %d",a+i,&n);
		int sum = a[i];
		int* b = (int*)malloc(sizeof(int)*2*n);
		for(j=0;j<2*n;j++) {scanf("%d",b+j); }
		for(j=0;j<2*n;j=j+2)
	    {
		    sum = sum+b[j]*b[j+1];
	    }
	    printf("%d\n",sum);
	}

	return 0;
}