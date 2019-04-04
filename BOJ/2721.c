#include <stdio.h>
int main()
{         
int n,t,i,k;
scanf("%d",&t);
for(i=0;i<t;i++)
{       
 scanf("%d",&n);
 int sum = 0;
 for(k=1;k<=n;k++)
 {
  sum = sum + (k*(k+1)*(k+2))/2;
 }  
 printf("%d\n",sum);
}   
return 0;
}