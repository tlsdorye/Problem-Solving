#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, M;
bool sel[10001];
vector<int> arr, ret;
set<vector<int>> check;


void Solve(int idx)
{
	if (ret.size() == M)
	{
		check.insert(vector<int>(ret));
		return;
	}
	for (int i = idx; i < N; i++)
	{
		if (sel[i]) continue;
		sel[i] = true;
		ret.push_back(arr[i]);
		Solve(i + 1);
		sel[i] = false;
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

	for (auto it : check) {
		for (int i = 0; i < it.size(); i++)
			printf("%d ", it[i]);
		printf("\n");
	}
}