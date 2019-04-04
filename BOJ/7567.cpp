#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char bowl[51];
int height;

int main()
{
	scanf("%s", bowl);
	height = 10;
	for (int i = 1; i < strlen(bowl); i++)
	{
		if (bowl[i - 1] == bowl[i]) height += 5;
		else height += 10;
	}
	printf("%d", height);
	return 0;
}
