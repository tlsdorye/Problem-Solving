#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, K, cnt= 0;
int D[101][101] = { 0 };
vector<int> ans;

bool bdck(int x, int y)
{
	return 0 <= x && x < M && 0 <= y && y < N;
}

int solve(int x,int y)
{
	if (D[x][y] != 0) return 0;
	int ret = 1;
	D[x][y] = ++cnt;
	queue<P> que;
	que.push(make_pair(x, y));
	while (!que.empty())
	{
		P curr = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int a = curr.first + dx[i], b = curr.second + dy[i];
			if (bdck(a, b) && D[a][b] == 0)
			{
				D[a][b] = cnt;
				ret++;
				que.push(make_pair(a, b));
			}
		}
	}
	return ret;
}

int main()
{
	cin >> M >> N >> K;
	int a, b, c, d;
	for (int i = 0; i < K; i++)
	{
		cin >> a >> b >> c >> d;
		for (int j = b; j < d; j++)
			for (int k = a; k < c; k++) D[j][k] = -1;
	}
	
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			int area = solve(i, j);
			if (area != 0) ans.push_back(area);
		}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}