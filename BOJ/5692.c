#include <stdio.h>
int main()
{
	int n, i;

	for (i = 0;i < 1;i = 0)
	{
		int ar[5] = { 0 };
		int arr[5] = { 0 };
		scanf("%d", &n);
		if (n == 0) break;
		ar[0] = n / 10000;
		n = n - (n / 10000)*10000;
		ar[1] = n / 1000;
		n = n - (n / 1000)*1000;
		ar[2] = n / 100;
		n = n - (n / 100)*100;
		ar[3] = n / 10;
		n = n - (n / 10)*10;
		ar[4] = n;
		arr[0] = ar[0] * 5 * 4 * 3 * 2;
		arr[1] = ar[1] * 4 * 3 * 2;
		arr[2] = ar[2] * 3 * 2;
		arr[3] = ar[3] * 2;
		arr[4] = ar[4];
		printf("%d\n", arr[0] + arr[1] + arr[2] + arr[3] + arr[4]);
	}
	return 0;
}