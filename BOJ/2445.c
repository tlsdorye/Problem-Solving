#include <stdio.h>
int main()
{
int n,i,k;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
 for(k=1;k<=(2*n);k++)
  { if(k<=i) printf("*");
    if(k>(2*n)-i) printf("*");
    if(k>i && k<=(2*n)-i) printf(" ");
  }
printf("\n");
}

for(i=1;i<=n-1;i++)
{
 for(k=1;k<=(2*n);k++)
 { if(k<=n-i) printf("*");
   if(k>(2*n)-n+i) printf("*");
   if(k>n-i && k<=(2*n)-n+i) printf(" ");
 }
if(i != n-1) printf("\n");
}
    return 0;
}