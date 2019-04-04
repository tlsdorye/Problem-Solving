#include <cstdio>

int a[100001] = { 0 };
int d[100001] = { 0 };
int r[100001] = { 0 };
int e[100001] = { 0 };
int n, sol = -100000001;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	d[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		if (d[i - 1] > 0) d[i] = a[i] + d[i - 1];
		else d[i] = a[i];
	}
	r[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (r[i + 1] > 0) r[i] = a[i] + r[i + 1];
		else r[i] = a[i];
	}
	if (n > 1) e[0] = r[1], e[n - 1] = d[n - 2];
	else e[0] = d[0], e[n - 1] = d[n - 1];
	for (int i = 1; i < n - 1; i++)
	{
		bool flag = true;
		if (d[i - 1] > 0) e[i] += d[i - 1], flag = false;
		if (r[i + 1] > 0) e[i] += r[i + 1], flag = false;
		if (flag) e[i] = -100000001;
	}
	for (int i = 0; i < n; i++)
		if (sol < d[i]) sol = d[i];
	for (int i = 0; i < n; i++)
		if (sol < e[i]) sol = e[i];
	printf("%d", sol);
	return 0;
}