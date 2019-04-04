#include <stdio.h>

int main()
{
int n,i,k;
scanf("%d",&n);
for(i=0;i<n;i++) {
for(k=0;k<n;k++) {
printf("*");} if(i!=n-1) printf("\n"); }
return 0;
}
