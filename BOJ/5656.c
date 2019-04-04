#include <stdio.h>

int main()
{
int i;
for(i=0;i<12000;i++)
{
  int a=0,b=0;
  char c=0,d=0;
  scanf("%d %c%c %d",&a,&c,&d,&b);

  if(c=='>' && d==' ' && a>b) printf("Case %d: true\n",i+1);
  if(c=='>' && d==' ' && a<=b) printf("Case %d: false\n",i+1);
  if(c=='>' && d=='=' && a>=b) printf("Case %d: true\n",i+1);
  if(c=='>' && d=='=' && a<b) printf("Case %d: false\n",i+1);
  if(c=='<' && d==' ' && a>=b) printf("Case %d: false\n",i+1);
  if(c=='<' && d==' ' && a<b) printf("Case %d: true\n",i+1);
  if(c=='<' && d=='=' && a>b) printf("Case %d: false\n",i+1);
  if(c=='<' && d=='=' && a<=b) printf("Case %d: true\n",i+1);
  if(c=='=' && d=='=' && a==b) printf("Case %d: true\n",i+1);
  if(c=='=' && d=='=' && a!=b) printf("Case %d: false\n",i+1);
  if(c=='!' && d=='=' && a!=b) printf("Case %d: true\n",i+1);
  if(c=='!' && d=='=' && a==b) printf("Case %d: false\n",i+1);
  if(c=='E' && d==' ') break;
}
return 0;
}