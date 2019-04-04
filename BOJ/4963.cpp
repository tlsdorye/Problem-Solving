#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int W, H, cnt = 0;
int M[51][51];
bool visit[51][51];
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };

bool bdck(int x, int y)
{
	return 0 <= x && x < H && 0 <= y && y < W;
}

void solve(int x,int y)
{
	if (M[x][y] != 1) return;
	if (visit[x][y]) return;
	queue<P> que;
	M[x][y] = --cnt;
	visit[x][y] = true;
	que.push(make_pair(x, y));
	while (!que.empty())
	{
		P curr = que.front();
		que.pop();
		for (int i = 0; i < 8; i++)
		{
			int a = curr.first + dx[i], b = curr.second + dy[i];
			if (bdck(a, b) && M[a][b] == 1 && !visit[a][b])
			{
				M[a][b] = cnt;
				visit[a][b] = true;
				que.push(make_pair(a, b));
			}
		}
	}
}

int main()
{
	cin >> W >> H;
	while (W != 0 && H != 0)
	{
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) cin >> M[i][j];
		cnt = 0;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) solve(i, j);
		printf("%d\n", -cnt);
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) visit[i][j] = false;
		cin >> W >> H;
	}
}