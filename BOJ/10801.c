#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[20];
	int i;
	int ch1 = 0, ch2 = 0;
	for(i=0;i<20;i++) scanf("%d",a+i);
	for(i=0;i<10;i++)
	{
		if(a[i]>a[10+i]) ch1++;
		else if(a[i]<a[10+i]) ch2++;
	}
	if(ch1>ch2) printf("A");
	if(ch1<ch2) printf("B");
	if(ch1==ch2) printf("D");
	return 0;
}