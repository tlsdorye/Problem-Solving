#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int sum, ans;
int A[10001];

int main()
{
	cin >> N >> M;
	int l = 0;
	for (int r = 0; r < N; r++)
	{
		scanf("%d", &A[r]);
		sum += A[r];
		while (sum > M) sum -= A[l++];
		if (sum == M) ans++;
	}
	cout << ans;
}