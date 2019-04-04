#include <stdio.h>

int main() {
	int olivers[9], start[9], a = 0, b = 0,check=0;
	for (int i = 0; i < 9; i++)
		scanf("%d", olivers + i);
	for (int i = 0; i < 9; i++)
		scanf("%d", start + i);

	for (int i = 0; i < 9; i++)
	{
		a += olivers[i];
		if (a > b) check = 1;
		b += start[i];
		if (a > b) check = 1;
	}
	if (check == 1)printf("Yes");
	else printf("No");
	return 0;
}