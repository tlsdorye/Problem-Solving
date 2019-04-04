#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int sum = 1;
	for(i=0;i<n;i++)
	{
	 sum=sum*(i+1);
	}
	printf("%d",sum);
	return 0;
}