#include <stdio.h>
int main()
{
	int test;
	int i, j, k;
	scanf("%d", &test);
	for ( i = 0; i < test;i++)
	{
		int r;
		scanf("%d", &r);
		getchar();
		for (k = 0; k < 1;)
		{
			char a;
			a = getchar();
			if (a == '\n') { printf("\n"); break; }
			for (j = 0; j < r; j++) printf("%c", a);
		}
	}

	return 0;
}