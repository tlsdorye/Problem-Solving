#include <stdio.h>

int main()
{
int a,i,k;
scanf("%d", &a);

for(i=0;i<a;i++)
{ for(k=0;k<(2*a)-1;k++)
 { if(k<i) printf(" ");
   if(k>=i && k<(2*a)-1-i) printf("*");
 }
printf("\n");
}

for (i=1;i<a;i++)
{ for(k=1;k<=(2*a)-1;k++)
 { if (k<=a-1-i) printf(" ");
   if (k>=a-i && k<a+1+i ) printf ("*");
  }
if (i != a-1) printf("\n");
}
return 0;
}