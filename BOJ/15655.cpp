#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> V;

int N, M;
V arr, ret;

void Solve(int idx)
{
	if (ret.size() == M)
	{
		for (int x : ret) printf("%d ", x);
		printf("\n");
		return;
	}
	for (int i = idx; i < N; i++)
	{
		ret.push_back(arr[i]);
		Solve(i + 1);
		ret.pop_back();
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	arr.resize(N, 0);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());

	Solve(0);
}