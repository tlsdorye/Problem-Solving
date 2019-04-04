#include <stdio.h>

int main()
{
float b=0.0;
char str[3];
scanf("%s", str);
switch(str[0]) {
case 'A': b=b+4.0;
break;
case 'B': b=b+3.0;
break;
case 'C': b=b+2.0;
break;
case 'D': b=b+1.0;
break;
case 'F': b=0;
break;}

switch(str[1]){
case '+': b=b+0.3;
break;
case '0': b=b+0;
break;
case '-' : b=b-0.3;
break;}

printf("%.1f", b);
return 0;
}