#include <stdio.h>
#include <algorithm>

using namespace std;

int d[1000100];

int main()
{
	int i, n;
	scanf("%d", &n);

	d[0] = d[1] = 0;
	d[2] = d[3] = 1;

	for (i = 4; i <= n; i++) {
		if ((i % 3 == 0) && (i % 2 == 0)) d[i] = min(d[i / 3], min(d[i / 2], d[i - 1])) + 1;
		else if (i % 3 == 0) d[i] = min(d[i / 3], d[i - 1]) + 1;
		else if (i % 2 == 0) d[i] = min(d[i / 2], d[i - 1]) + 1;
		else d[i] = d[i - 1] + 1;
	}
	printf("%d\n", d[n]);
}