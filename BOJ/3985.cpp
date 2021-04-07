#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int L, N;
int expected_ans, imax, real_ans;
int arr[1001], cnt[1001];

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> L >> N;
	
	int p, k;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &p, &k);
		if (imax < k - p + 1) 
		{
			expected_ans = i;
			imax = k - p + 1;
		}
		for (int j = p; j <= k; j++)
			if(arr[j] == 0) arr[j] = i;
	}
	for (int i = 1; i <= L; i++) cnt[arr[i]]++;
	imax = 0;
	for (int i = 1; i <= N; i++)
		if (imax < cnt[i])
		{
			real_ans = i;
			imax = cnt[i];
		}
	printf("%d\n%d", expected_ans, real_ans);
}