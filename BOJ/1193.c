#include <stdio.h>
int main()
{         
int i,k; 
int check = 0;
int x,y; 
scanf("%d",&x); 
for(i=1;1;i++)
{ x=x-i; check++;
  if(x<=i+1) {y=x; break;  }}
if(y==0 && check%2==0) printf("%d/%d",check,1);
if(y==0 && check%2==1) printf("%d/%d",1,check);
if(check%2==0) printf("%d/%d",check+2-y,y); 
if(check%2==1) printf("%d/%d",y,check+2-y); 
return 0; 
}