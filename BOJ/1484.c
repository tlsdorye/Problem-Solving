#include <stdio.h>
int main()
{         
int g;   
scanf("%d",&g);
int i,k,j;
int check = 0;
for(i=1;i<=g;i++)
{ if(g%i==0 && (g/i)<i) 
 { if( ((g/i)+i)%2==0) 
   { printf("%d\n",((g/i)+i)/2); check++;}
 }   
}   
if(check==0) printf("-1"); 
return 0; 
}