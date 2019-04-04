#include <stdio.h>

int main()
{        
int a = -1;
int b = -1;
int i;  

while(1)     
{     
scanf("%d %d", &a, &b);
if(a== 0 && b== 0) return 0;
printf("%d\n", a + b);
a = 0; b = 0; 
}   
return 0;
}                                         
