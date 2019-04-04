#include <stdio.h>
#include <stdlib.h>
#define SIZE 2187
int paper[SIZE][SIZE], A[3] = { 0 };
int size;
void divide(int x,int y,int z);
int* x = (int*)malloc(sizeof(int)*size / 3);
int* y = (int*)malloc(sizeof(int)*size / 3);
void input() {
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
		for (int k = 0; k < size; k++)
			scanf("%d", &paper[i][k]);
}

void conquer(int n,int q,int r) {
	int x = paper[q][r],check = 0;
	for (int i = q; i < q + n; i++)
	{
		for (int k = r; k < r + n; k++)
		{
			if (x != paper[i][k])
			{
				check = 1;
				divide(n, q, r);
				break;
			}
		}
		if (check == 1) break;
	}
	if (check == 0)	A[x + 1]++;
}
void divide(int n,int q,int r) {
	int S[3] = {0};
	for (int i = 0; i < 3; i++)
	{
		S[i] = (n / 3)*i ;
	}
	for (int i = 0; i < 3; i++)
		for (int k = 0; k < 3; k++)
			conquer(n/3,q+S[i],r+S[k]);

}

void output() {
	for (int i = 0; i < 3; i++)
		printf("%d\n", A[i]);
}

int main() {
	input();
	conquer(size,0,0);
	output();
	return 0;
}