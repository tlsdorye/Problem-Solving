#include <stdio.h>
int main()
{
 int n,i,k;
 scanf("%d",&n);
 for(i=0;i<n;i++){
 for(k=0;k<n+i;k++)
 { if(k<n-1-i) printf(" ");}
 for(k=0;k<n+i;k++)
 { if(k==n-1-i) printf("*");}
 for(k=n-i;k<n+i;k=k+2){
 printf(" "); printf("*");}
if(i!=n-1) printf("\n"); }
return 0;
}
