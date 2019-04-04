#include <stdio.h>

int main() {
	long long k, a, b, p, r, ans = 0;
	scanf("%lld %lld %lld", &k, &a, &b);
	if (0 <= a) {
		r = b / k;
		if (a%k == 0) p = a / k - 1;
		else p = a / k;
		ans = r - p;
	}
	else if (a < 0 && 0 < b) {
		r = b / k + 1;
		p = -a / k;
		ans = r + p;
	}
	else {
		p = -a / k;
		if (b%k == 0) r = -b / k - 1;
		else r = -b / k;
		ans = p - r;
	}
	printf("%lld", ans);
	return 0;
}