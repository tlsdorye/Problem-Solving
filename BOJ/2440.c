#include <stdio.h>
int main()
{         
int n;   
scanf("%d", &n);
for(int i=1;i<=n;i++)
{for(int k=0;k<n-i;k++)
  {printf("*");}
printf("*\n");}
return 0;
}
