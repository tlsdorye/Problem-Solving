#include <stdio.h>

int main()
{        
int t,i,k;
int a[301] = {0};
int b[301] = {0};
scanf("%d",&t);
 for(i=1;i<=t;i++) scanf("%d",a+i);
 for(i=0;i<=t;i++)
 {
  if(i==0 || i==1) b[i]=a[i];
  else if(i==2) b[i]=a[i]+a[i-1];
  else if(i==3) { if(a[i-1]>a[i-2]) b[i]=a[i]+a[i-1];
                  else b[i]=a[i]+a[i-2]; }
  else { if (b[i-3]+a[i-1]>b[i-2]) b[i]=b[i-3]+a[i-1]+a[i];
         else b[i]=b[i-2]+a[i]; } 
 }  
printf("%d",b[t]); 
return 0;
} 