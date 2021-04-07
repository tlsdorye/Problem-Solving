#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int N, M, K;
int board[11][11];
int A[11][11];
int dead_tree[11][11];
int dr[8][2] = { { -1, -1 },{ -1, 0 },{ -1, 1 },{ 0, -1 },{ 0, 1 },{ 1, -1 },{ 1, 0 },{ 1, 1 } };
vector<vector<deque<int>>> tree_age;

bool Check(int x, int y)
{
	return 1 <= x && x <= N && 1 <= y && y <= N;
}

void Print()
{
	printf("-----board-----\n");
	for (int i = 1; i <= N; i++, printf("\n"))
		for (int j = 1; j <= N; j++) printf("%2d ", board[i][j]);
	printf("-----dead_tree-----\n");
	for (int i = 1; i <= N; i++, printf("\n"))
		for (int j = 1; j <= N; j++) printf("%2d ", dead_tree[i][j]);
	printf("-----tree_age-----\n");
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			printf("board[%d][%d]: ", i, j);
			for (int k = 0; k < tree_age[i][j].size(); k++) printf("%d, ", tree_age[i][j][k]);
			printf("\n");
		}
	printf("\n");
}

void Solve()
{
	//spring
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			int pos = tree_age[i][j].size();
			for (int k = 0; k < tree_age[i][j].size(); k++)
			{
				if (tree_age[i][j][k] <= board[i][j]) board[i][j] -= tree_age[i][j][k]++;
				else dead_tree[i][j] += (tree_age[i][j][k] / 2), pos = min(pos, k);
			}
			tree_age[i][j].erase(tree_age[i][j].begin() + pos, tree_age[i][j].end());
		}
	//Print();
	//summer
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			board[i][j] += dead_tree[i][j];
			dead_tree[i][j] = 0;
		}
	//Print();
	// fall
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (auto it : tree_age[i][j])
			{
				if (it % 5 != 0) continue;
				for (int d = 0; d < 8; d++)
					if (Check(i + dr[d][0], j + dr[d][1])) tree_age[i + dr[d][0]][j + dr[d][1]].push_front(1);
			}
	//Print();
	//winter
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			board[i][j] += A[i][j];
	//Print();
}

int main()
{
	cin >> N >> M >> K;

	tree_age.resize(N + 1, vector<deque<int>>());
	for (int i = 1; i <= N; i++)
	{
		tree_age[i].resize(N + 1, deque<int>());
		for (int j = 1; j <= N; j++) board[i][j] = 5;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) scanf("%d", &A[i][j]);

	int x, y, z;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		tree_age[x][y].push_back(z);

	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			sort(tree_age[i][j].begin(), tree_age[i][j].end());

	for (int i = 1; i <= K; i++) Solve();

	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) ans += tree_age[i][j].size();
	cout << ans;
}