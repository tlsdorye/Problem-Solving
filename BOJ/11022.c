#include <stdio.h>
#include <stdlib.h>
int main()
{        
          
int t,i; 
scanf("%d",&t); 
int* a = (int*)malloc(sizeof(int)*t);
int* b = (int*)malloc(sizeof(int)*t);
      
for(i=0;i<t;i++) scanf("%d %d",a+i,b+i);
for(i=0;i<t;i++) printf("Case #%d: %d + %d = %d\n",(i+1) ,a[i],b[i], a[i] + b[i]);  
return 0;
}   
