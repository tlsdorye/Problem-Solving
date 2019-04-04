#include <stdio.h>
int main()
{
 int n,i,k;
 scanf("%d",&n);

 for(i=0;i<2*n-1;i++)
 { if(i<n){
   for(k=0;k<=i;k++) printf("*");
   printf("\n");}

   if(i>=n){
   for(k=0;k<2*n-i-1;k++) printf("*");
   if(i!=2*n-2)  printf("\n"); }
 }
return 0;
}