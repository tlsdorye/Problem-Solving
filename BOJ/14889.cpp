#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, ans = 1e9;
bool sel[21];
int map[21][21];
vector<int> A, B;

void getScore()
{
	int asum = 0, bsum = 0;
	for (int i = 0; i < A.size(); i++)
		for (int j = i + 1; j < A.size(); j++)
		{
			asum += map[A[i]][A[j]];
			bsum += map[B[i]][B[j]];
		}
	ans = min(ans, abs(asum - bsum));
}

void getTeam(int depth, int idx) 
{
	if (depth == N / 2) 
	{
		B.clear();
		for (int i = 0; i < N; i++)
			if (!sel[i]) B.push_back(i);
		getScore();
		return;
	}
	for (int i = idx; i < N; i++) 
	{
		sel[i] = true;
		A.push_back(i);
		getTeam(depth + 1, i + 1);
		sel[i] = false;
		A.pop_back();
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			if (i > j) map[j][i] += map[i][j];
		}
	getTeam(0, 0);
	cout << ans;
}