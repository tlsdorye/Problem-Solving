#include <stdio.h>
#include <stdlib.h>

long long result = 0;

void prime(long long A, long long B, long long b) {
	long long *arr;
	arr = (long long *)malloc(sizeof(long long) * (b+1));
	long long i = 2, sq;
	for (i = 2; i <= b; i++) {
		arr[i] = i;
	}

	for (i = 2; i <= b; i++) {
		if (arr[i] == 0) 
			continue;
		for (long long j = i + i; j <= b; j += i) { 
			arr[j] = 0;
		}
		sq = i*i;
		while (sq <= B)
		{
			if(sq >= A)	result++;
			if (B / sq >= i) sq *= i;
			else break;
		}
	}
}

int main() {
	long long A, B, b;
	scanf("%lld %lld", &A, &B);
	for (b = 1; b < B; b++)
		if (b*b > B)	break;
	prime(A,B,b);
	printf("%lld",result );
	return 0;
}

