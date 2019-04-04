#include <iostream>
#include <algorithm>
using namespace std;

char D[51][51];
int M, N, ans = 65;

char typeA[8][8] =
{
	{ 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' },
	{ 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' },
	{ 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' },
	{ 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' }
};

char typeB[8][8] = 
{
	{ 'B','W','B','W','B','W','B','W' },
	{ 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' },
	{ 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' },
	{ 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' },
	{ 'W','B','W','B','W','B','W','B' }
};

int solve(int s, int v)
{
	int Aans = 0, Bans = 0;
	for (int i = s, idx = 0; i < s + 8; i++, idx++)
		for (int j = v, jdx = 0; j < v + 8; j++, jdx++)
		{
			if (typeA[idx][jdx] != D[i][j]) Aans++;
			if (typeB[idx][jdx] != D[i][j]) Bans++;
		}
	return min(Aans, Bans);
}

int main()
{
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) cin >> D[i][j];

	for (int i = 0; i < M - 7; i++)
		for (int j = 0; j < N - 7; j++) ans = min(ans, solve(i, j));
	cout << ans;
}