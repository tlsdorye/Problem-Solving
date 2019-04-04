#include <stdio.h>
int main()
{
	int n, i, j;
	scanf("%d",&n);
	int a[3];
	int b[3]={0};
	int c[3]={0};
	for(i=0;i<n;i++)
	{
	    for(j=0;j<3;j++)   { scanf("%d",a+j);}
	    if(i==0)
	    {
	    for(j=0;j<3;j++){b[j]=a[j]; }}
	    
	    else
		{
	    	if(b[1]>=b[2]) c[0]=b[2]+a[0];
	    	else c[0]=b[1]+a[0];
	    	if(b[0]>=b[2]) c[1]=b[2]+a[1];
	    	else c[1]=b[0]+a[1];
	    	if(b[0]>=b[1]) c[2]=b[1]+a[2];
	    	else c[2]=b[0]+a[2];
	    	
	    	b[0]=c[0];
	    	b[1]=c[1];
	    	b[2]=c[2];
	    }
	}
	int min;
	min=b[0];
	for(i=1;i<3;i++)
	{
	if(min>=b[i]) min=b[i];
    }
    printf("%d",min);
	return 0;
}