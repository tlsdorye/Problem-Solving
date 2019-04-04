#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[4];
int ans = 0;

void hansu(int n)
{
	int a = n;
	fill(arr, arr + 3, 0);
	for (int i = 0; i < 4; i++)
	{
		arr[i] = a % 10;
		a = a / 10;
		if (a == 0) break;
	}
	if (n<100) ans++;
	else
	{
		int m = arr[0] - arr[1];
		if (arr[3] == 0 && m == arr[1]-arr[2]) ans++;
		else if (arr[3] != 0 && m==arr[1]-arr[2] && m == arr[2]-arr[3]) ans++;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) hansu(i);
	printf("%d", ans);
}