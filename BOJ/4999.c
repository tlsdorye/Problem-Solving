#include <stdio.h>

int main()
{
	int i, n = 104;
	int check1, check2;
	char a[1001] = { 0 };
	char b[1001] = { 0 };
	scanf("%s %s", a, b);
	for (i = 0; i < 1000; i++)
	{
		if (n == a[i]) { check1 = i; }
		if (n == b[i]) { check2 = i; }
	}
	if (check1 >= check2) printf("go");
	else printf("no");


	return 0;
}