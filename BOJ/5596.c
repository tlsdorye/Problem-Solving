#include <stdio.h>
int main()
{         
int a[4]={0}; 
int b[4]={0};
int i,k; 
for(i=0;i<4;i++)
{ scanf("%d",a+i);}
for(i=0;i<4;i++)
{ scanf("%d",b+i);}
if(a[0]+a[1]+a[2]+a[3] >=b[0]+b[1]+b[2]+b[3]) printf("%d",a[0]+a[1]+a[2]+a[3]);
else printf("%d",b[0]+b[1]+b[2]+b[3]); 
return 0;
}  