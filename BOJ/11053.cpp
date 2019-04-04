#include <stdio.h>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;
int n;
int a[1002], d[1002];
int lis(int idx)
{
	int ret = 1;
	if (d[idx] != -1) return d[idx];
	for (int i = idx-1; i >= 0; i--)
		if (a[i] < a[idx]) ret = max(ret, lis(i) + 1);
	d[idx] = ret;
	return d[idx];
}

int main()
{
	scanf("%d", &n);
	fill(d, d + n+1, -1);
	for (int i = 0; i < n; i++)	scanf("%d", a + i);
	a[n] = INF;
	printf("%d",lis(n)-1);
	return 0;
}