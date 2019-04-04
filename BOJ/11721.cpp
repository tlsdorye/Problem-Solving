#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char c[101];
	scanf("%s", c);
	int size = strlen(c);
	for (int i = 1; i<=size; i++)
	{
		printf("%c", c[i - 1]);
		if (i % 10 == 0) printf("\n");
	}
}