#include <stdio.h>

int main()
{
	int n,i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		char a[1001] = { 0 };
		int check = 0;
		scanf("%s", a);
		for (j = 0; a[j] != 0; j++)
		{
			check = j;
			
		}
		printf("%c%c\n",a[0],a[check] );
	}
	return 0;
}