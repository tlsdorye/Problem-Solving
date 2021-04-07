#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> arr, ret;
vector<bool> sel;


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
		Solve(i);
		ret.pop_back();
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	arr.resize(N, 0);
	sel.resize(N, false);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());

	Solve(0);
}