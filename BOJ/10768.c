#include <stdio.h>	
int main()
{
	int n,m;
	int i, k;
	scanf("%d %d", &n, &m);
	if(n==1) printf("Before");
	if(n == 2)
	{
		if (m == 18) printf("Special");
		if (m<18) printf("Before");
		if (m > 18) printf("After");
	}
	if(n>2)  printf("After");
	return 0;
}