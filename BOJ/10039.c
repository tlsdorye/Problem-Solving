#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n[5];
	int i,j;
	for(i=0;i<5;i++) scanf("%d",n+i);
	for(i=0;i<5;i++)
	{
		if(n[i]<=40) n[i]=40;
	}
	printf("%d",(n[0]+n[1]+n[2]+n[3]+n[4])/5);
	return 0;
}