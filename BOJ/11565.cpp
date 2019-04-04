#include <stdio.h>
#include <string.h>


char a[1001];
char b[1001];

int main() {
	scanf("%s %s", a, b);
	int x=0, y=0;
	for (int i = 0; i < strlen(a); i++)
		if (a[i] == '1') x++;
	for (int i = 0; i < strlen(b); i++)
		if (b[i] == '1') y++;
	if (x % 2 == 1) 
	{
		if (x + 1 < y) printf("DEFEAT");
		else printf("VICTORY");
	}
	else
	{
		if (x < y) printf("DEFEAT");
		else printf("VICTORY");
	}
	return 0;
}