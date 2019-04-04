#include <stdio.h>

int main()
{
	int i;
	int check = 0;
	for (i = 0; i < 1;)
	{
		char s;
		s = getchar();
		if (s == 97 || s == 101 || s == 105 || s == 111 || s == 117) check++;
		if (s == '\n') i = 1;
	}
	printf("%d", check);
	return 0;
}