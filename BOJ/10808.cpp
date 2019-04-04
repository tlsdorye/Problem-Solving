#include <stdio.h>
#include <cstring>

int a[123] = { 0 };
char c[101];

int main()
{
	scanf("%s", c);
	for (int i = 0; i < strlen(c); i++)	a[c[i]]++;
	for (int i = 'a'; i <= 'z'; i++) printf("%d ", a[i]);
	return 0;
}