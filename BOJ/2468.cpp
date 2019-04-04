#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int area[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool isVisit[101][101];

int N;


int solve(int x, int y, int H)
{
	if (isVisit[x][y]) return 0;
	isVisit[x][y] = true;

	if (area[x][y] <= H) return 0;

	for (int i = 0; i < 4; i++)
		{
			if (0 <= x + dx[i] && x + dx[i] < N && 0 <= y + dy[i] && y + dy[i] < N)
			{
				solve(x + dx[i], y + dy[i], H);
			}
		}
	return 1;
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> area[i][j];

	int ans = 1;
	int maxx = 0;

	for (int H = 1; H <= 100; H++) 
	{
		maxx = 0;
		memset(isVisit, 0, sizeof(isVisit));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				maxx += solve(i, j, H);
			}
		if (ans < maxx) ans = maxx;
	}

	cout << ans;
	return 0;
}