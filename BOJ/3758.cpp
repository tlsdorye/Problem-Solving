#include <iostream>
#include <algorithm>

using namespace std;

#include <stdio.h>

int f()
{
	int d[101][101] = { 0 };
	int dd[101] = { 0 };
	int ddd[101] = { 0 };
	int t1, k1, score;
	int n, k, t, m;
	scanf("%d %d %d %d", &n, &k, &t, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &t1, &k1, &score);
		dd[t1] = i;
		ddd[t1]++;
		if (d[t1][k1] < score) {
			d[t1][0] = d[t1][0] + score - d[t1][k1];
			d[t1][k1] = score;
		}
	}
	int count = 0;
	for(int i=1;i<=n;i++){
		if (i == t)continue;
		if (d[i][0] > d[t][0]) {
			count++;
//			printf("%d\n", i);
		}
		else if (d[i][0] == d[t][0] && ddd[i] < ddd[t]) {
			count++;
//			printf("%d", i);
		}
		else if (d[i][0] == d[t][0] && ddd[i] == ddd[t] && dd[i] < dd[t]) {
			count++;
//			printf("%d", i);
		}
	}
	return count+1;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		printf("%d\n",f());
	}
	return 0;
}