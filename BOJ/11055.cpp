#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, B[1000] = { 0 }, A[1000]{ 0 }, sum = 0,ans=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", A + i);
	for (int i = 0; i < n; i++)
	{
		int max = 0;
		sum = 0;
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && max < B[j])
				max = B[j];
		}
		sum = A[i] + max;
		B[i] = sum;
		if (ans < B[i]) ans = B[i];
	}
		printf("%d ", ans);
		return 0;
}