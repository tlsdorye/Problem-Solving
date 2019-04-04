#include <stdio.h>
int main()
{
	int a,b,n;
	scanf("%d %d %d",&a,&b,&n);
	a = a+ n/60+(n%60+b)/60;
	b = (n%60+b)%60;
	if(a>=24) a=a-24;
	printf("%d %d",a,b);
	return 0;
}