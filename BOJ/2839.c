#include <stdio.h>
int main()
{
	int sug, five, three ;
	scanf("%d", &sug);
	five = sug / 5;
	sug = sug % 5;
	three = sug / 3;
	sug = sug % 3;
	if (sug == 0)	printf("%d", five + three);
	else if (sug == 1)
	{
		if (five >= 1)
		{
			five = five - 1;
			three = three + 2;
			printf("%d", five + three);
		}
		else printf("-1");
	}
	else if (sug == 2)
	{
		if (five >= 2)
		{
			five = five - 2;
			three = three + 4;
			printf("%d", five + three);
		}
		else printf("-1");
	}

	return 0;
}