#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
const int MAX = 10001;
const int INF = 1000000001;
typedef pair<int, int> P;

int N, M, L, MAX_IDX;
int A[MAX], B[MAX], dist[MAX];
bool used[MAX], visit[MAX];
vector<int> adj[MAX], adx, bdx;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int arr[101][101];

set<P> sep;
vector<P> ans;

bool bdcheck(int x, int y) 
{
	return 1 <= x && x <= N && 1 <= y && y <= M;
}

void makeGraph()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			arr[i][j] = (i - 1) * M + j;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (!bdcheck(nx, ny)) continue;
				if (sep.find({ arr[i][j], arr[nx][ny] }) != sep.end()) continue;
				adj[arr[i][j]].push_back(arr[nx][ny]);
			}
}

void makeBipartite()
{
	queue<P> que;
	que.push({ 1, 1 });
	bool visit[101][101] = { false };
	visit[1][1] = true;

	int level = 0;
	while (!que.empty())
	{
		int qsize = que.size();
		for (int i = 0; i < qsize; i++)
		{
			P cur = que.front();
			que.pop();
			if (level % 2 == 0) adx.push_back(arr[cur.first][cur.second]);
			else bdx.push_back(arr[cur.first][cur.second]);
			for (int j = 0; j < 4; j++)
			{
				int nx = cur.first + dx[j];
				int ny = cur.second + dy[j];
				if (!bdcheck(nx, ny)) continue;
				if (visit[nx][ny]) continue;
				visit[nx][ny] = true;
				que.push({ nx, ny });
			}
		}
		level++;
	}
}

void bfs()
{
	queue<int> que;
	for (int a : adx)
	{
		if (!used[a])
		{
			dist[a] = 0;
			que.push(a);
		}
		else dist[a] = INF;
	}
	while (!que.empty())
	{
		int a = que.front();
		que.pop();
		for (int b : adj[a])
		{
			if (B[b] != -1 && dist[B[b]] == INF)
			{
				dist[B[b]] = dist[a] + 1;
				que.push(B[b]);
			}
		}
	}
}

bool dfs(int a)
{
	if (visit[a]) return false;
	visit[a] = true;
	for (int b : adj[a])
	{
		if (B[b] == -1 || dist[B[b]] == dist[a] + 1 && dfs(B[b]))
		{
			used[a] = true;
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> N >> M >> L;
	int a, b;
	for (int i = 0; i < L; i++)
	{
		cin >> a >> b;
		sep.insert({ a, b });
		sep.insert({ b, a });
	}
	makeGraph();
	makeBipartite();
	MAX_IDX = N * M + 1;

	fill(A, A + MAX_IDX, -1);
	fill(B, B + MAX_IDX, -1);

	while (1)
	{
		bfs();
		int flow = 0;
		for (int a : adx)
		{
			fill(visit, visit + MAX_IDX, false);
			if (!used[a] && dfs(a)) flow++;
		}
		if (flow == 0) break;
	}

	for (int a : adx) printf("%d %d\n", a, A[a]);
}