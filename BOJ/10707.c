#include <stdio.h>
int main()
{
	int a,b,c,d,p;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&p);
	if(p>c)
	{
	  if(a*p > b+(p-c)*d) printf("%d",b+(p-c)*d);
	  else printf("%d",a*p);
    }
    else if(p<=c)
    {
    	if(a*p > b)printf("%d",b);
    	else printf("%d",a*p);
	}
	return 0;
}