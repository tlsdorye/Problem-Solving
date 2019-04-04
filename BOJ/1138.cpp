#include <stdio.h>
int N, A[10], B[10] = { 0 };
void greed(int size) {
	
	for (int i = 0; i < size; i++)
	{
		for (int k = 0,j = 0; k < size; k++)
		{
			if (B[k] == 0)
			{
				if (A[i] == j)
				{
					B[k] = i + 1;
					break;
				}
				else j++;
			}
		}
	}
		
}

int main()
{
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)	scanf("%d", &A[i]);
	greed(N);
	for (int i = 0; i < N; i++)	printf("%d ", B[i]);
	return 0;
}