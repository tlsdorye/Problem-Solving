#include <stdio.h>

int a[300][300], b[300][300], c[300][300];

int main() {
	int size,sum = 0;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
		for (int k = 0; k < size; k++)
			scanf("%d", &a[i][k]);
	for (int i = 0; i < size; i++)
		for (int k = 0; k < size; k++)
			scanf("%d", &b[i][k]);
	for (int i = 0; i < size; i++)
		for (int k = 0; k < size; k++)
			for (int j = 0; j < size; j++) {
				c[i][k] += a[i][j] * b[j][k];
				if (c[i][k] > 0) {
					sum++;
					break;
				}
			}
	printf("%d", sum);
	return 0;
}
