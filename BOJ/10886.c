#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	int i,j;
	int ch1 = 0, ch2 = 0;
	scanf("%d",&n);
	int* a = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){ scanf("%d",a+i); }
	for(i=0;i<n;i++)
	{
		if(a[i]==1) ch1++;
		else if (a[i]==0) ch2++;
	}
	if(ch1<ch2) printf("Junhee is not cute!");
	else if (ch1>ch2)printf("Junhee is cute!");
	return 0;
}