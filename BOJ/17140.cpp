#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, int> P;

int R, C, K;
int maxR, maxC;
int grid[1010][1010];
int cnt[1010];

vector<P> arr;

bool compare(P &x, P&y)
{
	if (x.second < y.second) return true;
	else if(x.second == y.second) return x.first < y.first;
	return false;
}

void ComputeR()
{
	int tmp = 0;
	for (int i = 1; i <= maxR; i++)
	{
		arr.clear();
		for (int j = 1; j <= 100; j++) cnt[j] = 0;
		for (int j = 1; j <= maxC; j++)
		{
			cnt[grid[i][j]]++;
			grid[i][j] = 0;
		}
		for (int j = 1; j <= 100; j++)
			if (cnt[j] != 0) arr.push_back({ j, cnt[j] });
		sort(arr.begin(), arr.end(), compare);
		for (int j = 0; j < arr.size(); j++)
		{
			grid[i][j * 2 + 1] = arr[j].first;
			grid[i][j * 2 + 2] = arr[j].second;
		}
		tmp = max(tmp, (int)arr.size() * 2);

	}
	maxC = max(maxC, tmp);
}

void ComputeC()
{
	int tmp = 0;
	for (int j = 1; j <= maxC; j++)
	{
		arr.clear();
		for (int i = 1; i <= 100; i++) cnt[i] = 0;
		for (int i = 1; i <= maxR; i++)
		{
			cnt[grid[i][j]]++;
			grid[i][j] = 0;
		}
		for (int i = 1; i <= 100; i++)
			if (cnt[i] != 0) arr.push_back({ i, cnt[i] });
		sort(arr.begin(), arr.end(), compare);
		for (int i = 0; i < arr.size(); i++)
		{
			grid[i * 2 + 1][j] = arr[i].first;
			grid[i * 2 + 2][j] = arr[i].second;
		}
		tmp = max(tmp, (int)arr.size() * 2);
	}
	maxR = max(maxR, tmp);
}

void printGrid()
{
	printf("%2d %2d\n", maxR, maxC);
	for (int i = 1; i <= maxR; i++, printf("\n"))
		for (int j = 1; j <= maxC; j++)
			printf("%2d ", grid[i][j]);
	printf("\n");
}

int Solve()
{
	int ans = 0;
	//printGrid();
	while (grid[R][C] != K && ans <= 100)
	{
		ans++;
		if (maxR >= maxC) ComputeR();
		else ComputeC();
		//printGrid();
	}
	if (ans > 100) ans = -1;
	return ans;
}


int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> R >> C >> K;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			scanf("%d", &grid[i][j]);
	maxR = 3;
	maxC = 3;
	printf("%d", Solve());
}