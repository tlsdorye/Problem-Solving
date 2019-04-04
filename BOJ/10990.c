#include <stdio.h>
int main()
{
 int a,i,k;
scanf("%d",&a);

for(i=0;i<a;i++){
for(k=0;k<2*a-1;k++){
if(k<a-1-i ||( k>a-1-i  && k<a-1+i)) printf(" ");
if(k==a-i-1 || k==a-1+i) printf("*");}
if(i!=a-1) printf("\n");}
return 0;
}
