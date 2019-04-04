#include <stdio.h>
long long f[120] = { 1,1,1,0 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 3; i < 120; i++) f[i] = f[i - 1] + f[i - 3];
	printf("%lld", f[n - 1]);
	return 0;
}