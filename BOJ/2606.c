#include <stdio.h>
#include <stdlib.h>

int main()
{
int m, t, i, k ;
int z;
scanf("%d %d",&m, &t);
int* a = (int*)malloc(sizeof(int)*m);
int* b = (int*)malloc(sizeof(int)*2*t);
for(i=0;i<2*t;i++) scanf("%d",b+i);

int sum = 0;
for(i=0;i<m;i++) a[i]=i+1;
for(k=0;k<101;k++){
for(i=0;i<2*t;i=i+2){
if(a[b[i]-1]==1 || a[b[i+1]-1]==1)
{ a[b[i]-1]=1; a[b[i+1]-1]=1;}}}
for(i=1;i<m;i++)if(a[i]==1) {sum = sum+1;}
printf("%d",sum);
return 0;
}
