#include <stdio.h>
int main()
{
 int n,i,j;
 scanf("%d",&n);
 getchar();
 for(i=0;i<n;i++)
 {
  int a[26]={0};
  char c=0;
  for(j=0;c!='\n';j++)
  {
   c=getchar();
   a[c-65]++;
  }
  int sum=0;
  for(j=0;j<26;j++)
   if(a[j]==0) sum=sum+j+65;
  printf("%d\n",sum);
 }
 return 0;
}