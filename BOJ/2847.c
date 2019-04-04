#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,j;
	int check = 0;
	scanf("%d",&n);
	
	int* a = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{	scanf("%d",a+i);	}
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<1;)
	    {
		  if(a[n-1-i]<=a[n-2-i]) { a[n-2-i] = a[n-2-i]-1; check++; }
		  else if(a[n-1-i]>a[n-2-i]) j=1;
	    }
    }
	printf("%d",check);
	
	return 0;
}