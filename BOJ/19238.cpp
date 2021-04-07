#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

class Customer
{
public:
	int x, y, d, cdx;
	Customer(int x, int y, int d, int cdx)
	{
		this->x = x;
		this->y = y;
		this->d = d;
		this->cdx = cdx;
	}
};

int N, M, F, X, Y;
int grid[21][21];
bool visit[21][21];
map<int, P> goal;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool bdCheck(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < N;
}

bool comp(const Customer &a, const Customer &b)
{
	if (a.d < b.d) return true;
	else if (a.d == b.d)
	{
		if (a.x < b.x) return true;
		else if (a.x == b.x)
		{
			if (a.y < b.y) return true;
		}
	}
	return false;
}

int ToCustomer()
{
	fill(&visit[0][0], &visit[20][21], false);
	visit[X][Y] = true;

	queue<P> que;
	que.push({ X, Y });

	vector<Customer> customers;

	int level = 0;
	while (!que.empty())
	{
		if (level > F) break;
		int qsize = que.size();
		for (int i = 0; i < qsize; i++)
		{
			P cur = que.front();
			que.pop();

			int cx = cur.first;
			int cy = cur.second;
			if (grid[cx][cy] >= 2) 
				customers.push_back(Customer(cx, cy, level, grid[cx][cy]));

			for (int j = 0; j < 4; j++)
			{
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (!bdCheck(nx, ny)) continue;
				if (visit[nx][ny]) continue;
				if (grid[nx][ny] == 1) continue;
				visit[nx][ny] = true;
				que.push({ nx, ny });
			}
		}
		level++;
	}
	if (customers.empty()) return -1;
	sort(customers.begin(), customers.end(), comp);
	Customer cur = customers[0];
	F -= cur.d;
	grid[cur.x][cur.y] = 0;
	X = cur.x;
	Y = cur.y;
	return cur.cdx;
}

int ToGoal(int cdx)
{
	fill(&visit[0][0], &visit[20][21], false);

	queue<P> que;
	que.push({ X, Y });
	visit[X][Y] = true;

	int level = 0;
	while (!que.empty())
	{
		if (level > F) return -1;
		int qsize = que.size();
		for (int i = 0; i < qsize; i++)
		{
			P cur = que.front();
			que.pop();
			if (goal[cdx] == cur)
			{
				X = cur.first;
				Y = cur.second;
				F += level;
				return 1;
			}
			for (int j = 0; j < 4; j++)
			{
				int nx = cur.first + dx[j];
				int ny = cur.second + dy[j];
				if (!bdCheck(nx, ny)) continue;
				if (visit[nx][ny]) continue;
				if (grid[nx][ny] == 1) continue;
				que.push({ nx, ny });
				visit[nx][ny] = true;
			}
		}
		level++;
	}
	return -1;
}

int solve()
{
	for (int i = 0; i < M; i++)
	{
		int cdx = ToCustomer();
		if (cdx < 0) return -1;
		
		cdx = ToGoal(cdx);
		if (cdx < 0) return -1;
	}
	return F;
}

int main()
{
	cin >> N >> M >> F;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			cin >> grid[i][j];

	cin >> X >> Y;
	X--, Y--;
	int a, b, c, d;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c >> d;
		grid[a - 1][b - 1] = i + 2;
		goal[i + 2] = { c - 1, d - 1 };
	}
	cout << solve();
}
