#include <stdio.h>
int main()
{         
         
int n,i,a,b;
int c=0; 
int d=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{     
 scanf("%d %d",&a,&b);
 if(a>b) c=c+1;
 else if(a<b) d=d+1;
}   
printf("%d %d",c,d);
return 0;
}