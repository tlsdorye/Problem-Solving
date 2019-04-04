#include <stdio.h>

int d[1001];
int a[1001];

int set(int n) {
	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}
	int max = d[0];
	for (int i = 1; i<n; i++)
	{
		if (d[i] > max) max = d[i];
	}
	return max;
}

int main() {
	int n, max = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", a + i);
	printf("%d", set(n));
	return 0;
}