#include <stdio.h>

int main()
{        
          
int a,b,c,d,i,k;
scanf("%d %d %d %d",&a,&b,&c,&d);
i=(a+b+c+d)/60;
k=(a+b+c+d)%60;
printf("%d\n%d",i,k); 
return 0;
}