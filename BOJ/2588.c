#include <stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d %d",&a,&b);
	c=(b%10)*a;
	d=((b-b%10)/10)%10*a;
	e=(b/100)*a;
	f=c+10*d+100*e;
	printf("%d\n%d\n%d\n%d",c,d,e,f);
	return 0;
}