#include <stdio.h>

int main()
{
int t, n, i, k;
scanf("%d",&t);

for(i=0;i<t;i++)
{            
 int c=0;
 int d=0;
 scanf("%d",&n);
  for(k=0;k<n;k++) 
   {
     char a=0;
     char b=0;
     scanf("\n%c %c",&a,&b); 
     if(a=='P' && b=='R') c++;
     else if(a=='P' && b=='S') d++;
     else if(a=='R' && b=='P') d++; 
     else if(a=='R' && b=='S') c++;
     else if(a=='S' && b=='P') c++;
     else if(a=='S' && b=='R') d++;
   }
     if(c>d) printf("Player 1\n");
     else if(c<d) printf("Player 2\n");
     else if(c==d) printf("TIE\n");
}
return 0;
}