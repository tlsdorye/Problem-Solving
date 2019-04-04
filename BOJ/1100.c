#include <stdio.h>

int main()
{
	char a;
	int i, j, k;
	int check1 = 0, check2 = 0;
	for (i = 0; i < 1;)
	{
		a = getchar();
		if (check1 % 2 == 0 && a == 70) check2++;
		if (check1 == 71) i = 1;
		check1++;
	}
	printf("%d", check2);
	return 0;
}