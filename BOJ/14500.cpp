#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> P;

int N, M;
int arr[501][501];

vector<vector<P>> tetros = {
	{{ 0, -2 },{ 0, -1 },{ 0, 0 },{ 0, 1 } },
	{{ -1, 0 },{ -1, 1 },{ 0, 0 },{ 0, 1 }},
	{{ -2, 0 },{ -1, 0 },{ 0, 0 },{ 0, 1 }},
	{{ -2, 0 },{ -1, 0 },{ 0, 0 },{ 0, -1 }},
	{{ -1, -1 },{ 0, -1 },{ 0, 0 },{ 1, 0 }},
	{{ -1, 1 },{ 0, 1 },{ 0, 0 },{ 1, 0 }},
	{{ -1, 0 },{ 0, -1 },{ 0, 0 },{ 0, 1 }}
};

bool CheckBD(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < M;
}

void Rotate(vector<P> &tetro) 
{
	int x, y;
	for (int i = 0; i < 4; i++)
	{
		x = -tetro[i].second;
		y = tetro[i].first;
		tetro[i].first = x;
		tetro[i].second = y;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);

	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int t = 0; t < 7; t++)
				for (int r = 0; r < 4; r++)
				{
					Rotate(tetros[t]);
					bool check = true;
					for (int k = 0; k < 4; k++)
						if (!CheckBD(tetros[t][k].first + i, tetros[t][k].second + j))
						{
							check = false;
							break;
						}
					if (!check) continue;
					int sum = 0;
					for (int k = 0; k < 4; k++)
						sum += arr[tetros[t][k].first + i][tetros[t][k].second + j];
					ans = max(ans, sum);
				}
	cout << ans;
}
