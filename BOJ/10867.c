#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,k;
	int min;
	int b[2002] = {1001};
	scanf("%d",&n);
	int* a = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{ scanf("%d",a+i);}
	for(i=1;i<=2001;i++)
	{ min = 1001;
		if(i==1) { 	   
		 for(k=0;k<n;k++)
	       { if(min > a[k]) min = a[k];}
		 b[i]=min; } 
		 
		 
		else{
			for(k=0;k<n;k++)
			{    if( a[k] > b[i-1] && min>a[k])  min = a[k];  }
			b[i] = min;    }
	}
	
	for(i=1;i<=2001;i++)
	{
		if(b[i] == 1001) break;
		else  printf("%d ",b[i]);
	}
     return 0;
 }
			

	
	