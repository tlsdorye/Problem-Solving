#include <stdio.h>

int main()
{
int n,i,k;
scanf("%d",&n);
for(i=0;i<n;i++)
{
  for(k=0;k<n-i-1;k++) printf(" ");
  for(k=0;k<1+(2*i);k++) printf("*");
  printf("\n");
}
for(i=1;i<n;i++)
{
  for(k=0;k<i;k++) printf(" ");
  for(k=0;k<(2*n)-(2*i)-1;k++) printf("*");
  if(i != n-1) printf("\n");

}


return 0;
}
