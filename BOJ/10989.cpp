#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int d[10001] = { 0 };

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int x;
		scanf("%d", &x);
		d[x]++;
	}
	for (int i = 1; i <= 10000; i++)
		for (int j = 0; j < d[i]; j++)
			printf("%d\n", i);
}