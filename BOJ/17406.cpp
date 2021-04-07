#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

typedef pair<int, int> P;

class T
{
public:
	int r, c, s;
	T() {}
	T(int r, int c, int s)
	{
		this->r = r;
		this->c = c;
		this->s = s;
	}
};

int N, M, K, ans = 1e9;
int A[51][51];
int copy_A[51][51];
vector<T> op, order;
bool sel[6];

int Calculate();

void PrintGrid()
{
	for (int i = 0; i < N; i++, printf("\n"))
		for (int j = 0; j < M; j++)
			printf("%2d", A[i][j]);
	printf("%d\n\n", Calculate());
}

void Rotate()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			copy_A[i][j] = A[i][j];

	for (T t : order)
	{
		int r = t.r, c = t.c;
		for (int s = 1; s <= t.s; s++)
		{
			int temp = copy_A[r - s][c - s];
			for (int i = 0; i < s * 2; i++) copy_A[r - s + i][c - s] = copy_A[r - s + i + 1][c - s];
			for (int i = 0; i < s * 2; i++) copy_A[r + s][c - s + i] = copy_A[r + s][c - s + i + 1];
			for (int i = 0; i < s * 2; i++) copy_A[r + s - i][c + s] = copy_A[r + s - i - 1][c + s];
			for (int i = 0; i < s * 2; i++) copy_A[r - s][c + s - i] = copy_A[r - s][c + s - i - 1];
			copy_A[r - s][c - s + 1] = temp;
		}
		//PrintGrid();
	}
}

int Calculate()
{
	int ret = 1e9;
	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = 0; j < M; j++) sum += copy_A[i][j];
		ret = min(ret, sum);
	}
	return ret;
}

void Solve(int depth)
{
	if (depth >= K)
	{
		Rotate();
		ans = min(ans, Calculate());
		return;
	}
	for (int i = 0; i < K; i++)
	{
		if (sel[i]) continue;
		sel[i] = true;
		order.push_back(op[i]);
		Solve(depth + 1);
		sel[i] = false;
		order.pop_back();
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &A[i][j]);

	int r, c, s;
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d %d", &r, &c, &s);
		op.push_back({ r - 1, c - 1, s });
	}
	Solve(0);
	printf("%d", ans);
}