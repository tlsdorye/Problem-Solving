#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    int i,j;
    int a[5];
    int check = 0;
    scanf("%d",&n);
    for(i=0;i<5;i++) scanf("%d",a+i);
    for(i=0;i<5;i++)
    {
    	if(a[i]==n) check++;
	}
	printf("%d",check);
	return 0;
}