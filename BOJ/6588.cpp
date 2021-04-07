#include <iostream>
using namespace std;

int N;

int prime[1000001];

void getPrime()
{
	prime[1] = true;
	for (int i = 3; i < 1000; i+=2) {
		if (prime[i]) continue;
		for (int j = i * 2; j <= 1000000; j += i)
			prime[j] = true;
	}
}

int main()
{
	getPrime();
	scanf("%d", &N);
	while (N != 0) 
	{
		for (int i = 3; i <= N / 2; i += 2) {
			if (!prime[i] && !prime[N - i]) {
				printf("%d = %d + %d\n", N, i, N - i);
				break;
			}
		}
		scanf("%d", &N);
	}
}
