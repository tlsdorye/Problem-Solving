#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
typedef pair<int, int> P;
typedef vector<bool> V;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int R, C, ans = 1;
char board[21][21];
bool visit[21][21] = { false };
V v(26, false);

bool bdck(int x, int y)
{
	return 0 <= x && x < R && 0 <= y && y < C;
}

void solve(int x, int y, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (bdck(a, b))
			if (!visit[a][b] && !v[board[a][b] - 'A'])
			{
				visit[a][b] = true;
				v[board[a][b] - 'A'] = true;
				cnt++;
				if (ans < cnt) ans = cnt;
				solve(a, b, cnt);
				visit[a][b] = false;
				v[board[a][b] - 'A'] = false;
				cnt--;
			}
	}
}


int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) cin >> board[i][j];

	visit[0][0] = true;
	v[board[0][0] - 'A'] = true;
	solve(0, 0, 1);
	cout << ans;

}