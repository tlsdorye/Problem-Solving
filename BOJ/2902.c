#include <stdio.h>

int main()
{
	int i;

	for (i = 0; i<1;)
	{
		char a;
		a = getchar();
		if (65 <= a && a <= 90) printf("%c", a);
		if (a == '\n')i = 1;
	}
	return 0;
}