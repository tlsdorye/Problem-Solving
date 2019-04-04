#include <stdio.h>


int main(void) {
	int n, nine[10000],i=0;
	scanf("%d", &n);
	while (1) {
		nine[i] = n % 9;
		n /= 9;
		if (n == 0) break;
		i++;
	}
	for (i; i >=0; i--) printf("%d", nine[i]);
	return 0;
}
