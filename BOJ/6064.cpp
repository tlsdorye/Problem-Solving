#include<stdio.h>
int f()
{
	int n, m, x, y,a,b,count=0,k;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	a = b = 1;
	while (1) {
		if (x - a == y - b) {
			count = count + x - a + 1;
			break;
		}
		if (n - a > m - b) {
			a = a + m - b + 1;
			count = count + m - b + 1;
			b = 1;
		}
		else if (n - a < m - b) {
			b = b + n - a + 1;
			count = count + n - a + 1;
			a = 1;
		}
		else if (n - a == m - b) {
			count = count + n - a + 1;
			a = b = 1;
		}
		if (a == 1 && b == 1 && count!=0) {
			count = -1;
			break;
		}
	}
	printf("%d\n",count);
	return 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		f();
	}
	return 0;
}