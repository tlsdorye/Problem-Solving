#include <iostream>
using namespace std;
int N;

int main()
{
	int a;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		if ((a&(-a)) == a) printf("1\n");
		else printf("0\n");
	}
	return 0;
}