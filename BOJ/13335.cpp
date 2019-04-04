#include <stdio.h>
int d[10000001];
int t[1001];
int main()
{
	int n, w, l, time = 0, sum = 0, i, k, e;
	int t[1001];
	scanf("%d %d %d", &n, &w, &l);
	for (i = 1; i <= n; i++) scanf("%d", &t[i]);
	t[0] = d[0] = 0;
	while (1) {
		d[0]++;
		e = d[0] - w;
		if (e < 1)k = 0;
		else k = d[e];
		sum = sum - k;
		if (sum + t[t[0] + 1]<=l && t[0] + 1 <= n) {
			t[0]++;
			d[d[0]] = t[t[0]];
			sum = sum + t[t[0]];
		}
		else d[d[0]] = 0;
		if (t[0] >= n && sum == 0)break;
		time++;
	}
	printf("%d", time+1);
	return 0;
}