#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[10] = {0};
	int m,i,k;
	for(i=0;i<10;i++) scanf("%d",a+i);
	
	for(i=0;i<10;i++)
	{
		for(k=0;k<9;k++)
		{
			if(a[k]>a[k+1])
			{
				m=a[k+1]; a[k+1]=a[k]; a[k]=m;
			}
		}
	}
	int ch1 = 0, ch2 = 0;
	int max = 0;
	for(i=0;i<10;i++)
	{
		if(a[i]==a[i+1])
		{
			ch1++;
			if(max<ch1) { max =ch1; ch2 =i;}
		}
		else if(a[i]!=a[i+1]) ch1 = 0;
	}
	int sum = 0;
	for(i=0;i<10;i++) sum = sum+a[i];
	
	printf("%d\n%d",sum/10,a[ch2]);
	return 0;
}