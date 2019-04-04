#include <stdio.h>

int d[20000] = { 0 };

int sn(int n)
{
	if (n < 10) return n;
	return sn(n / 10) + n % 10;
}

void solve(int n)
{
	int x = sn(n);
	d[n + x] = 1;
}

int main()
{
	for (int i = 1; i < 10001; i++) solve(i);
	for (int i = 1; i < 10001; i++)
		if (d[i] == 0) printf("%d\n", i);
	return 0;
}