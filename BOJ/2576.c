#include <stdio.h>
int main() {
		int sum = 0;
		int min = 987654321;
		int num[7] = {0};
		for (int i = 0; i < 7; i++)
			scanf("%d", &num[i]);
		for (int i = 0; i < 7; i++)
			if (num[i] % 2 == 1) {
				sum += num[i];
				if (min >= num[i])
					min = num[i];
			}
		if (sum == 0)
		{
			printf("-1");
		}
		else printf("%d\n%d", sum, min);
	return 0;
}