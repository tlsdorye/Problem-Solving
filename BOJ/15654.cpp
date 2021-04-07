#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
vector<int> ret;
vector<bool> sel;

void Solve(int r)
{
	if (r >= M)
	{
		for (int x : ret) printf("%d ", x);
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (sel[i]) continue;
		sel[i] = true;
		ret[r] = arr[i];
		Solve(r + 1);
		sel[i] = false;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	ret.resize(M, 0);
	sel.resize(N, 0);
	int x;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());


	Solve(0);
}