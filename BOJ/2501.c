#include <stdio.h>

int main()
{        
int n, m, i, k;
int check =0; 
scanf("%d %d",&n,&m);
for(i=1;i<=n;i++)
{            
  if(n%i==0) check++; 
  if(check==m) {printf("%d",i); break;}
}
if(check<m) printf("0"); 
return 0;
} 