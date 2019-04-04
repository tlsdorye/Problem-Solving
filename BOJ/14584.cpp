#include <stdio.h>
#include <string.h>
int main() {
	char a[52], code[101], decode[101], word[20][21];
	char* x = NULL ;
	int tc, n = 0;
	for (int i = 0; i < 52; i++)
	{
		a[i] = i+1;
		if (i > 25) a[i] = i - 25;
	}
	scanf("%s %d", code, &tc);
	for (int i = 0; i < tc; i++)	scanf("%s", word[i]);
	for (int i = 0; code[i] != NULL; i++)	code[i] = code[i] - 96;
	while (1)
	{
		for (int i = 0; code[i]!=NULL; i++)
		{
			code[i]++;
			decode[i] = a[code[i]]+96;
			if (code[i + 1] == NULL) decode[i + 1] = NULL;
		}
		for (int i = 0; i < tc; i++)
		{
			x = strstr(decode, word[i]);
			if (x != NULL)
			{
				n = 1;
				break;
				
			}
		}
		if (n == 1)break; 
	}
	printf("%s", decode);
	return 0;
}