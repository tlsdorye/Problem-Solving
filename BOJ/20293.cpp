#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> P;

int R, C, N, r, c, f;
int fuel[3001][3001];
int dp[1002];
vector<P> arr;

bool isGoal(int idx)
{
	fill(&dp[0], &dp[1002], -1);
	dp[0] = idx;

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			int cx = arr[i].first, cy = arr[i].second;
			int nx = arr[j].first, ny = arr[j].second;
			int dist = (nx - cx) + (ny - cy);
			if (cx > nx || cy > ny) continue;
			if (dp[i] < 0) continue;
			if (fuel[cx][cy] + dp[i] < dist) continue;
			dp[j] = max(dp[j], dp[i] - dist + fuel[cx][cy]);
		}
	}
	//for (int i = 0; i < arr.size(); i++)
	//	printf("[%d %d]: %d\n", arr[i].first, arr[i].second, dp[i]);

	if (dp[arr.size() - 1] >= 0) return true;
	return false;
}

int solve(int start, int end)
{
	int mid = (start + end) / 2;
	//printf("[%d %d %d]\n", start, mid, end);
	if (start == mid)
	{
		if (isGoal(mid)) return mid;
		else return end;
	}
	if (isGoal(mid)) return solve(start, mid);
	else return solve(mid + 1, end);
}

int main()
{
	cin >> R >> C >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> r >> c >> f;
		fuel[r][c] = f;
		arr.push_back({ r, c });
	}
	arr.push_back({ 1, 1 });
	arr.push_back({ R, C });
	sort(arr.begin(), arr.end());
	cout << solve(1, R + C - 2);
}