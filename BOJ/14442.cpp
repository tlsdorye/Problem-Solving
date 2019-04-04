#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Node
{
public:
	int x, y, k, m;
	Node(int x, int y, int k, int m)
	{
		this->x = x;
		this->y = y;
		this->k = k;
		this->m = m;
	}
};

int D[1001][1001], visit[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, K;

bool check(Node p)
{
	int x = p.x;
	int y = p.y;
	int k = p.k;
	return 1 <= x && x <= N && 1 <= y && y <= M && k <= K;
}

Node solve(Node p)
{
	queue<Node> que;
	que.push(p);
	while (!que.empty())
	{
		Node cur = que.front();
		if (cur.x == N && cur.y == M && cur.k <= K)
		{
			cur.m += 1;
			return cur;
		}
		que.pop();
		for (int j = 0; j < 4; j++)
		{
			Node next = Node(cur.x + dx[j], cur.y + dy[j], cur.k, cur.m + 1);
			if (check(next))
			{
				if (D[next.x][next.y] == 1)
				{
					next.k += 1;
					if (next.k > K) continue;
				}
				if (visit[next.x][next.y] == -1)
				{
					visit[next.x][next.y] = next.k;
					que.push(next);
				}
				else
				{
					if (visit[next.x][next.y] > next.k)
					{
						visit[next.x][next.y] = next.k;
						que.push(next);
					}
				}
			}
		}
	}
	return Node(N, M, K, -1);
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &D[i][j]);
			visit[i][j] = -1;
		}
	Node ans = solve(Node(1, 1, 0, 0));
	cout << ans.m;
}
