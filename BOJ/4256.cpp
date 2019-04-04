#include <stdio.h>

int index = 1;
int preArr[1001], inArr[1001];

void order(int s, int e) {
	for (int i = s; i <= e; i++) {
		if (preArr[index] == inArr[i]) {
			index++;
			if (s <= i-1)
				order(s, i - 1);
			if (i + 1 <= e)
				order(i + 1, e);
			printf("%d ", inArr[i]);
			return;
		}
	}
}

int main() {
	int T, n;

	scanf("%d", &T);

	while (T--) {
		index = 1;

		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &preArr[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &inArr[i]);
		}

		order(1, n);
		printf("\n");
	}

	return 0;
}