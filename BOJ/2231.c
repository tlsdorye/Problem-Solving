#include <stdio.h>
int main()
{         
int n,i,k;
int a=0,c=0;
scanf("%d",&n);
int b[1010000] = {0};
for(i=1;i<=1000000;i++)
{ a = i;     
  c = i;
  for(k=1;k<=8;k++)
   { 
     a = a + c%10; 
     c= (c-c%10)/10; 
     if(c==0)  break; 
   }
  if(b[a]==0 || b[a]>=i) b[a] =i; 
}   
printf("%d",b[n]); 
return 0;
}