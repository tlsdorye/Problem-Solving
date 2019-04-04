#include <stdio.h>
int main()
{
 int n,i,k;
 scanf("%d",&n);

 for(i=0;i<n-1;i++){
 for(k=0;k<2*n-1;k++){
 if(k<n-1-i) printf(" ");
 if(k>n-1-i && k<n-1+i) printf(" ");
 if(k==n-1-i || k==n-1+i) printf("*"); }
 printf("\n");}

for(i=0;i<2*n-1;i++) printf("*");
return 0;
}