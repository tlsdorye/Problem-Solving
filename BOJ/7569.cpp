#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

ll N, M, H, ans;
ll D[101][101][101];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

class TP
{
public:
	ll x, y, z;
	TP(ll a, ll b, ll c)
	{
		x = a, y = b, z = c;
	}
};

queue<TP> que;

bool check(ll x, ll y, ll z)
{
	return 1 <= x && x <= H && 1 <= y && y <= N && 1 <= z && z <= M;
}

void solve()
{
	while (!que.empty())
	{
		ll qSize = que.size();
		for (int j = 0; j < qSize; j++)
		{
			TP curr = que.front();
			que.pop();
			for (int i = 0; i < 6; i++)
			{
				ll nx = curr.x + dx[i];
				ll ny = curr.y + dy[i];
				ll nz = curr.z + dz[i];
				if (check(nx,ny,nz) && D[nx][ny][nz] == 0)
				{
					D[nx][ny][nz] = 1;
					que.push(TP(nx, ny, nz));
				}
			}
		}
		ans++;
	}
}

int main()
{
	cin >> M >> N >> H;

	bool flag = false;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= M; k++)
			{
				scanf("%lld", &D[i][j][k]);
				if (D[i][j][k] == 0) flag = true;
				else if (D[i][j][k] == 1) que.push(TP(i, j, k));
			}
	if (!flag)
	{
		cout << "0";
		return 0;
	}
	solve();
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= M; k++)
				if (D[i][j][k] == 0)
				{
					cout << "-1";
					return 0;
				}
	cout << ans - 1;
	return 0;
}