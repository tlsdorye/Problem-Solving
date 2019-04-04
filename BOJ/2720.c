#include <stdio.h>
#include <stdlib.h>
int main()
{
	int t,i;
	scanf("%d",&t);

	int* a = (int*)malloc(sizeof(int)*t);
	for(i=0;i<t;i++) scanf("%d",a+i);
	for(i=0;i<t;i++)
	{
		int b[4] = {0};
		b[0] = a[i]/25; 
		b[1] = a[i]%25/10;
		b[2] = a[i]%25%10/5;
		b[3] = a[i]%25%10%5/1;
		printf("%d %d %d %d\n",b[0],b[1],b[2],b[3]);
	}
	return 0;
}