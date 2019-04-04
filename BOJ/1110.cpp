#include <cstdio>

int main()
{
	int n, k;
	int t = 100, ans = 0;

	scanf("%d", &n);

	if (n < 10)
		n *= 10;

	k = n;

	while (k != t)
	{
		t = (n % 10) * 10 + ((n / 10) + (n % 10)) % 10;
		n = t;
		ans++;

	}

	printf("%d\n", ans);

	return 0;
}