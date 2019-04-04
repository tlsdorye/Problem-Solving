#include<stdio.h>
int d[1002][1002];
int q[1000001][3];
int main()
{
	int n, m, i, j, s=1, e=1;
	bool ans = false;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		getchar();
		for (j = 1; j <= m; j++) {
			scanf("%c", &d[i][j]);
		}
	}
	d[1][0] = d[1][m + 1] = 1;
	for (j = 1; j <= m; j++) {
		d[0][j] = 1;
		d[n + 1][j] = 1;
		d[1][j] = d[1][j] - 48;
		if (d[1][j] == 0) {
			q[e][1] = 1;
			q[e][2] = j;
			e++;
			d[1][j] = 1;
		}
	}
	for (i = 2; i <= n; i++) {
		d[i][0] = 1;
		d[i][m+1] = 1;
		for (j = 1; j <= m; j++) {
			d[i][j] = d[i][j] - 48;
		}
	}
	while (1) {
		if (s >= e)break;
		if (q[s][1] == n) {
			ans = true;
			break;
		}
		if (d[q[s][1]+1][q[s][2]] == 0) {
			q[e][1] = q[s][1]+1;
			q[e][2] = q[s][2];
			d[q[e][1]][q[e][2]] = 1;
			e++;
		}
		if (d[q[s][1]-1][q[s][2]] == 0) {
			q[e][1] = q[s][1]-1;
			q[e][2] = q[s][2];
			d[q[e][1]][q[e][2]] = 1;
			e++;
		}
		if (d[q[s][1]][q[s][2]+1] == 0) {
			q[e][1] = q[s][1];
			d[q[e][1]][q[e][2]] = 1;
			q[e][2] = q[s][2]+1;
			e++;
		}
		if (d[q[s][1]][q[s][2]-1] == 0) {
			q[e][1] = q[s][1];
			q[e][2] = q[s][2]-1;
			d[q[e][1]][q[e][2]] = 1;
			e++;
		}
		s++;
		
	}
	if (ans)printf("YES");
	else printf("NO");
	return 0;
}