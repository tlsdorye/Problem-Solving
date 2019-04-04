#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int D[5000002], M[5000002];


int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &D[i]);
	nth_element(D, D + K - 1, D + N);
	printf("%d\n", D[K-1]);
}