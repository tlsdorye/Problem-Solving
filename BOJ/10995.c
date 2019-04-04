#include <stdio.h>
int main()
{
int n,i,k;
scanf("%d",&n);

for(i=0;i<n;i=i+2){
for(k=0;k<2*n-3;k=k+2){ printf("* ");} printf("*"); if(i!=n-1) printf("\n");
if(i!=n-1){for(k=0;k<2*n-1;k=k+2){printf(" *");} if(i!=n-2)  printf("\n");}}

return 0;
}