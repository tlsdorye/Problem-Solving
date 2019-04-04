#include <stdio.h>
int main()
{
	char a[8] = {0};
	char b[8] = {0};
	char c[8] = {0};
	char d[8] = {0};
	int i,t;
	int sum;
	int q,w,e,r;
	scanf("%s %s",a,b);
	for(i=0;i<8;i++)
	{
		c[i]=a[i];
		d[i]=b[i];
		if(c[i]=='6') c[i]='5';
		if(d[i]=='6') d[i]='5';
		if(a[i]=='5') a[i]='6';
		if(b[i]=='5') b[i]='6';
	}
	t=1; sum = 0;
	for(i=7;i>=0;i--)
 	  {  if(a[i] != 0) {  sum =sum+(int)(a[i]-48)*t; t=10*t;  } }
 	  t=1; q=sum; sum=0;
    for(i=7;i>=0;i--)
	  {  if(b[i] != 0) {  sum =sum+(int)(b[i]-48)*t; t=10*t;  } }
	  t=1; w=sum; sum=0;
    for(i=7;i>=0;i--)
	  {  if(c[i] != 0) {  sum =sum+(int)(c[i]-48)*t; t=10*t;  } }
	  t=1; e=sum; sum=0;
    for(i=7;i>=0;i--)
	  {  if(d[i] != 0) {  sum =sum+(int)(d[i]-48)*t; t=10*t;  } }
	 
	r=sum;
	 printf("%d %d",e+r,q+w);
}