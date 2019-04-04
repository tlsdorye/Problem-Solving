#include <stdio.h>
#include <string.h>
char a[10];
int eig(int b)
{

	int k = 1,sum=0,i;
	for (i = b - 1; i >= 1; i--) {
		sum = sum + k*(a[i] - 48);
		k = k * 8;
	}
	return sum;
}

int sixt(int b)
{
	int k = 1, sum = 0, i;
	for (i = b - 1; i >= 2; i--) {
		a[i] = a[i] >= 97 ? a[i] - 87 : a[i]-48;
		sum = sum + k*(a[i]);
		k = k * 16;
	}
	return sum;
}

int main()
{
	int b,sum;
	scanf("%s", a);
	b = strlen(a);
	if (a[0] == '0'&& a[1] != 'x') printf("%d",eig(b));
	else if (a[0] == '0' && a[1] == 'x') printf("%d",sixt(b));
	else printf("%s", a);
	return 0;
}