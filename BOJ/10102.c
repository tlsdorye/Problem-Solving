#include <stdio.h>

int main()
{
	int v, i;
	int ch1 = 0, ch2 = 0;
	scanf("%d", &v);
	getchar();
	for (i = 0; i < 1;)
	{
		char a;
		a = getchar();
		if (a == '\n') break;
		if (a == 65) ch1++;
		if (a == 66) ch2++;
	}
	if (ch1 > ch2) printf("A");
	if (ch1 == ch2) printf("Tie");
	if (ch1 < ch2) printf("B");

	return 0;
}