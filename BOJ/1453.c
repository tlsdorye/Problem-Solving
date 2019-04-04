#include <stdio.h>

int main()
{        
int a, i; 
int b[100] = {0};
int c[101] = {0};
int count = 0;
scanf("%d", &a);
for(i=0;i<a;i++) scanf("%d",b+i);

for(i=0;i<a;i++)
{   
  if(b[i] != 0 )
  { 
    if(c[b[i]] ==1) {count++;}
    else if(c[b[i]] ==0) {c[b[i]] =1;}
  } 
}   
printf("%d", count);
    
return 0;
}
