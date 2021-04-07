#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int N, M, T, X, D, K, ans;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector<deque<int>> disk;

void Rotate()
{
	for (int i = X - 1; i < N; i += X)
		for (int j = 0; j < K; j++)
		{
			if (D == 0)
			{
				disk[i].push_front(disk[i].back());
				disk[i].pop_back();
			}
			else
			{
				disk[i].push_back(disk[i].front());
				disk[i].pop_front();
			}
		}
}

bool BFS()
{
	queue<P> que;
	bool is_same = false;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (disk[i][j] < 0) continue;
			int val = disk[i][j];
			que.push({ i, j });
			while (!que.empty())
			{
				P cur = que.front();
				que.pop();

				int cx = cur.first;
				int cy = cur.second;
				for (int d = 0; d < 4; d++)
				{
					int nx = cx + dx[d];
					int ny = (cy + dy[d] + M) % M;
					if (nx < 0 || nx >= N) continue;
					if (val != disk[nx][ny]) continue;
					disk[cx][cy] = -1;
					disk[nx][ny] = -1;
					is_same = true;
					que.push({ nx, ny });
				}
			}
		}
	return is_same;
}

void Flatten()
{
	int cnt = 0;
	float avg = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (disk[i][j] >= 1)
			{
				avg += disk[i][j];
				cnt++;
			}
	avg /= cnt;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (disk[i][j] < 0) continue;
			if (disk[i][j] > avg) disk[i][j]--;
			else if (disk[i][j] < avg) disk[i][j]++;
		}
}

int main()
{
	cin >> N >> M >> T;

	int n;
	for (int i = 0; i < N; i++)
	{
		disk.push_back(deque<int>());
		for (int j = 0; j < M; j++)
		{
			cin >> n;
			disk[i].push_back(n);
		}
	}

	for (int i = 0; i < T; i++)
	{
		cin >> X >> D >> K;
		Rotate();
		if (!BFS()) Flatten();
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (disk[i][j] > 0) 
				ans += disk[i][j];

	cout << ans;
}