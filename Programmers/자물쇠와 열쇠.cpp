#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;
vector<vector<int>> rotate(vector<vector<int>>& key);
void print(vector<vector<int>>& map);
bool check(vector<vector<int>>& map, vector<vector<int>>& key, int x, int y, int N);


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int M = key.size();
	int N = lock.size();
	int K = N + 2 * M - 2;
	vector<vector<int>> map(K, vector<int>(K, 0));

	for (int i = M - 1; i < N + M - 1; i++)
		for (int j = M - 1; j < N + M - 1; j++)
			map[i][j] = lock[i - M + 1][j - M + 1];

	for (int k = 0; k < 4; k++)
	{
		key = rotate(key);
		//print(key);
		for (int i = 0; i < K - M + 1; i++)
		{
			bool flag = true;
			for (int j = 0; j < K - M + 1; j++)
			{
				if (!check(map, key, i, j, N))
				{
					//printf("%2d %2d %2d: false\n", k, i, j);
					flag = false;
				}
				else
				{
					//printf("%2d %2d %2d: true\n", k, i, j);
					return true;
				}
			}
			if (flag) break;
		}
	}
	return false;
}

vector<vector<int>> rotate(vector<vector<int>>& key)
{
	int M = key.size();
	vector<vector<int>> ret(M, vector<int>(M, 0));
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			ret[i][j] = key[-j + M - 1][i];
	return ret;
}

void print(vector<vector<int>>& map)
{
	for (int i = 0; i < map.size(); i++, printf("\n"))
		for (int j = 0; j < map[i].size(); j++)
			printf("%d ", map[i][j]);
}

bool check(vector<vector<int>>& map, vector<vector<int>>& key, int x, int y, int N)
{
	bool ret = true;
	int M = key.size();
	for (int i = x; i < x + M; i++)
		for (int j = y; j < y + M; j++)
			map[i][j] += key[i - x][j - y];

	for (int i = M - 1; i < N + M - 1; i++)
	{
		for (int j = M - 1; j < N + M - 1; j++)
			if (map[i][j] != 1)
			{
				ret = false;
				break;
			}
		if (!ret) break;
	}

	for (int i = x; i < x + M; i++)
		for (int j = y; j < y + M; j++)
			map[i][j] -= key[i - x][j - y];

	return ret;
}