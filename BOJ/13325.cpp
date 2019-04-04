#include<stdio.h>

int max = 0;
int arr[1 << 22] = { 0 };

void search(int h, int a, int s) {
	if (h == arr[1]) {
		if (max < s)
			max = s;
		return;
	}
	search(h + 1, 2 * a, s + arr[2 * a]);
	search(h + 1, 2 * a + 1, s + arr[2 * a + 1]);
	return;
}

int solve(int h, int a, int s) {
	int l = 0, r = 0;
	if (h == arr[1])
		return (max - s);

	l = solve(h + 1, 2 * a, s + arr[2 * a]);
	r = solve(h + 1, 2 * a + 1, s + arr[2 * a + 1]);

	if (l > r) {
		arr[2 * a] += (l - r);
		return r;
	}
	else {
		arr[2 * a + 1] += (r - l);
		return l;
	}
}

int main() {
	scanf("%d", &arr[1]);
	for (int i = 2; i < (1 << (arr[1] + 1)); i++)
		scanf("%d", &arr[i]);

	search(0, 1, 0);
	solve(0, 1, 0);
	
	max = 0;

	for (int i = 2; i < (1 << (arr[1] + 1)); i++)
		max += arr[i];

	printf("%d", max);

	return 0;
}