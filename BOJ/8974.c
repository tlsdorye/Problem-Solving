#include <stdio.h>
int main()
{         
int i,j,k,n,m;
int check = 0;
int a[1000] = {0};
int sum = 0;
for(i=1;1;i++){
for(j=0;j<i;j++){
a[check]=i; check++; if(check==1000) break;}
if(check==1000) break;}
scanf("%d %d",&n,&m);
for(i=0;i<m;i++){
sum=sum+a[i]; 
if(i==n-2) k=sum; } 
printf("%d",sum-k);
return 0;
} 