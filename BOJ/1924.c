#include <stdio.h>

int main()
{
	int a,b,sum ,i ;
	sum=0;
	scanf("%d %d",&a,&b);
	
	switch(a)
	{
		case 12:
			sum=sum+30;
		case 11:
		    sum=sum+31;
		case 10:
			sum=sum+30;
		case 9:
		    sum=sum+31;
		case 8:
			sum=sum+31;
		case 7:
		    sum=sum+30;
		case 6:
			sum=sum+31;
		case 5:
		    sum=sum+30;
		case 4:
			sum=sum+31;
		case 3:
		    sum=sum+28;
		case 2:
			sum=sum+31;
		    break;
	}
	sum =sum +b;
	
		if(sum%7==1)
		{
			printf("MON");
		}
		if(sum%7==2)
		{
			printf("TUE");
		}
		if(sum%7==3)
		{
			printf("WED");
		}
		if(sum%7==4)
		{
			printf("THU");
		}
		if(sum%7==5)
		{
			printf("FRI");
		}
		if(sum%7==6)
		{
			printf("SAT");
		}
		if(sum%7==0)
		{
			printf("SUN");
		}										
	
 return 0;	
}