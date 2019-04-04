#include <stdio.h>

int main()
{
	int i;
	int check = 0;
	for (i = 0; i < 1;)
	{
		char s;
		
		s = getchar();
		if (s == 44) check++;
		if (s == '\n')i = 1;
	}
	printf("%d", check + 1);
	return 0;
}