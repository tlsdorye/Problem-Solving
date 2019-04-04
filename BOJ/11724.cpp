#include <iostream>
#include <vector>
using namespace std;

int N, M, ans = 0;
vector < vector<int> > D;
int visit[1001];

void solve(int s)
{
	if (visit[s] != 0) return;
	visit[s] = ans;
	for (int i = 0; i < D[s].size(); i++) solve(D[s][i]);
}

int main()
{
	cin >> N >> M;
	D.resize(N + 1, vector<int>());
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		D[x].push_back(y);
		D[y].push_back(x);
	}

	for (int i = 1; i < D.size(); i++)
		if (visit[i] == 0)
		{
			ans++;
			solve(i);
		}
	cout << ans;
	return 0;
}