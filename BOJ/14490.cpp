#include <stdio.h>

int U(int a, int b) {
	int temp;
	temp = a%b;
	if (temp == 0)
		return b;
	else
		U(b, temp);
}
int M(int a, int b) {
	int temp;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
		return U(a,b);
	}
	else return U(a, b);
}
int main(void) {
	int x, y;
	scanf("%d:%d", &x, &y);
	printf("%d:%d", x / M(x, y), y / M(x, y));
	return 0;
}
