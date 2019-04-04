#include <stdio.h>

int main()
{
	int n, sum = 0, m = 0,v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v);
		sum += v;
		m = (m < v) ?  v : m;
	}
	printf("%d", sum - m);
	return 0;
}