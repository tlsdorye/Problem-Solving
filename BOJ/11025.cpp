#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

int main()
{
	cin >> N >> K;
	
	int ANS = 0;
	for (int i = 1; i <= N; i++)
		ANS = (ANS + K) % i;
	printf("%d", ANS + 1);
}